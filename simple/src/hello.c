/*
 * hello.c              Copyright NXP 2016
 * Description:  Simple program to exercise GPIO
 * 2015 Mar 31 S Mihalik/ O Romero - initial version
 *
 */

/*Modified 09.05.2018 by ADiea for simplification of code base*/

#include "S32K144_small.h"    /* include peripheral declarations S32K144 */

#define LED_BLUE	GPIO_Pin_0         /* Port PTD0, bit 0: FRDM EVB output to blue LED */
#define LED_RED		GPIO_Pin_15
#define LED_GREEN	GPIO_Pin_16

#define BTN_0		GPIO_Pin_12        /* Port PTC12, bit 12: FRDM EVB input from BTN0 [SW2] */
#define BTN_1		GPIO_Pin_13

void WDOG_disable (void)
{
	  /* Write of the WDOG unlock key to CNT register, must be done in order to allow any modifications*/
	  WDOG->CNT = (uint32_t ) FEATURE_WDOG_UNLOCK_VALUE;

	  /* The dummy read is used in order to make sure that the WDOG registers will be configured only
	   * after the write of the unlock value was completed. */
	  (void)WDOG->CNT;

	  /* Initial write of WDOG configuration register:
	   * enables support for 32-bit refresh/unlock command write words,
	   * clock select from LPO, update enable, watchdog disabled */
	  WDOG->CS  = (uint32_t ) ( (1UL << WDOG_CS_CMD32EN_SHIFT)                       |
	                            (FEATURE_WDOG_CLK_FROM_LPO << WDOG_CS_CLK_SHIFT) 	 |
	                            (0U << WDOG_CS_EN_SHIFT)                             |
	                            (1U << WDOG_CS_UPDATE_SHIFT)                         );

	  /* Configure timeout */
	  WDOG->TOVAL = (uint32_t )0xFFFF;
}

int main(void)
{
  int counter = 0;

  WDOG_disable();             /* Disable Watchdog in case it is not done in startup code */
                              /* Enable clocks to peripherals (PORT modules) */

  //Clock Configuration

  PCC->PORTC_CLK = PCC_PCCn_CGC_MASK;
  PCC->PORTD_CLK = PCC_PCCn_CGC_MASK;

  //GPIO Configuration

  GPIOC->PDDR &= ~(1<<BTN_0);    /* Port C12: Data Direction= input (default) */
  PORTC->PCR[GPIO_Pin_12] = (AFIO_GPIO << PCR_MUX) | (1 << PCR_PFE); /* Port C12: MUX = GPIO, input filter enabled */
                               /* Configure port D0 as GPIO output (LED on EVB) */
  GPIOC->PDDR &= ~(1<<BTN_1);
  PORTC->PCR[GPIO_Pin_13] = (AFIO_GPIO << PCR_MUX) | (1 << PCR_PFE);

  GPIOD->PDDR |= (1<<LED_BLUE);        /* Port D0: Data Direction= output */
  PORTD->PCR[GPIO_Pin_0] = (AFIO_GPIO << PCR_MUX);  /* Port D0: MUX = GPIO */

  GPIOD->PDDR |= (1<<LED_RED);
  PORTD->PCR[GPIO_Pin_15] = (AFIO_GPIO << PCR_MUX);

  GPIOD->PDDR |= (1<<LED_GREEN);
  PORTD->PCR[GPIO_Pin_16] =(AFIO_GPIO << PCR_MUX);

  for(;;) {
	if( GPIOC->PDIR & (1<<BTN_1) ){
		counter++;
	}

    if (GPIOC->PDIR & (1<<BTN_0)) {
    	if( counter % 3 == 0){
    		GPIOD->PCOR |= 1 << LED_BLUE;
    	}

    	if( counter % 3 == 1){
    		GPIOD->PCOR |= 1 << LED_RED;
    	}

    	if( counter % 3 == 2){
    		GPIOD->PCOR |= 1 << LED_GREEN;
    	}
    }
    else {
      GPIOD-> PSOR |= (1<<LED_BLUE) | (1<<LED_RED) | (1<<LED_GREEN);
    }
  }
}
