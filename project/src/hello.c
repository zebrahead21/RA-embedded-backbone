/*
 * hello.c              Copyright NXP 2016
 * Description:  Simple program to exercise GPIO
 * 2015 Mar 31 S Mihalik/ O Romero - initial version
 *
 */

/*Modified 09.05.2018 by ADiea for simplification of code base*/

#include "S32K144_small.h"    /* include peripheral declarations S32K144 */
#include "gpio.h"
#include "timer.h"

#define BTN_0		GPIO_Pin_12        /* Port PTC12, bit 12: FRDM EVB input from BTN0 [SW2] */
#define BTN_1		GPIO_Pin_13
#define NUMBER_BUTTONS 2

typedef enum{
	LED_ON,
	LED_OFF
}eLedState;

#define LED_OFF 1

#define CPU_FREQ 48000000
#define WHILE_INSTRUCTIONS (4*90)
#define BUTTON_TEST_DELAY (CPU_FREQ / WHILE_INSTRUCTIONS)

typedef enum {
	eBtn_NotPressed,
	eBtn_Pressed,
	eBtn_Released,
	eBtn_LongPress,
}eButtonPress;

typedef enum{
	LED_BLUE = GPIO_Pin_0,
	LED_RED = GPIO_Pin_15,
	LED_GREEN = GPIO_Pin_16,
}eLED;

typedef enum{
	eButtonLeft = BTN_1,
	eButtonRight = BTN_0,
}eButton;

typedef enum
{
	ePWMLED_BLUE = eFTM_CH2,
	ePWMLED_RED = eFTM_CH0,
	ePWMLED_GREEN = eFTM_CH1,
}eLEDPWMChannels;

uint32_t buttonDelay[NUMBER_BUTTONS];

//experimentally determined a calibration factor, it is not accurate
#define EXPERIMENTAL_CALIB 8
void cpuDelayMs(uint32_t ms)
{
	uint32_t counter;
	while(ms--)
	{
		//delay 1ms
		counter = CPU_FREQ / EXPERIMENTAL_CALIB / 1000;
		while(counter--);
	}
}

void PORTC_IRQHandler(void)
{

	//verify which pin was pressed

	//set global variable OR directly take action


}

void turnLEDOn(eLED led)
{
	setPinValue(GPIOD, LED_BLUE, LED_OFF);
	setPinValue(GPIOD, LED_RED, LED_OFF);
	setPinValue(GPIOD, LED_GREEN, LED_OFF);

	setPinValue(GPIOD, led, LED_ON);
}

void turnLEDOff(eLED led)
{
	setPinValue(GPIOD, led, LED_OFF);
}

eButtonPress isPressed(eButton btn)
{
	if(getPinValue(GPIOC, btn)) //button is pressed
	{
		if(buttonDelay[btn] < BUTTON_TEST_DELAY)
		{
			buttonDelay[btn]++;
			return eBtn_Pressed;
		}
		else
		{
			return eBtn_LongPress;
		}
	}
	else if(buttonDelay[btn] > 0) //button is not pressed check if it was pressed last time
	{
		buttonDelay[btn] = 0;
		return eBtn_Released;
	}

	return eBtn_NotPressed;
}

void waitButtonRelease(eButton btn)
{
	while(getPinValue(GPIOC, btn))
	{
		;
	}
}



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

#define LEDPWN_CNTIN_VAL 0
#define LEDPWN_MOD_VAL 255

//Using flexible timer 0 for controlling RGB LED with PWM
void timer0Init()
{
	//RCC enable timer0
	PCC->PCC_FTM0 = PCC_PCCn_CGC_MASK;

	setPinFunction(PORTD, LED_BLUE, eAF_pinAF2);
	setPinFunction(PORTD, LED_RED, eAF_pinAF2);
	setPinFunction(PORTD, LED_GREEN, eAF_pinAF2);

	enablePWMOutput(FTM0, ePWMLED_BLUE, ePWM_enabled, LEDPWN_CNTIN_VAL, LEDPWN_MOD_VAL);
	enablePWMOutput(FTM0, ePWMLED_RED, ePWM_enabled, LEDPWN_CNTIN_VAL, LEDPWN_MOD_VAL);
	enablePWMOutput(FTM0, ePWMLED_GREEN, ePWM_enabled, LEDPWN_CNTIN_VAL, LEDPWN_MOD_VAL);

	setPWMDUty(FTM0, ePWMLED_BLUE, 0);
	setPWMDUty(FTM0, ePWMLED_RED, 0);
	setPWMDUty(FTM0, ePWMLED_GREEN, 0);

	//configure timer 0
	selectClockSource(FTM0, eCS_FTM_InClk);
	selectPrescaleFactor(FTM0, ePF_DivBy128);

}

void init_RGB_GPIO(void)
{
	  setPinDirection(GPIOD, LED_BLUE, ePinDir_Output);
	  setPinFunction(PORTD, LED_BLUE, eAF_pinGPIO);
	  //todo set led off

	  setPinDirection(GPIOD, LED_RED, ePinDir_Output);
	  setPinFunction(PORTD, LED_RED, eAF_pinGPIO);

	  setPinDirection(GPIOD, LED_GREEN, ePinDir_Output);
	  setPinFunction(PORTD, LED_GREEN, eAF_pinGPIO);

}

int main(void)
{
  eLED whichLED = 0;
  eButtonPress leftButPressState;
  eButtonPress rightButPressState;
  int factorR = 0;
  int factorG = 0;
  int factorB = 0;

  WDOG_disable();             /* Disable Watchdog in case it is not done in startup code */
                              /* Enable clocks to peripherals (PORT modules) */



  //Clock Configuration
  PCC->PORTC_CLK = PCC_PCCn_CGC_MASK;
  PCC->PORTD_CLK = PCC_PCCn_CGC_MASK;

  timer0Init();

  //GPIO Configuration
  setPinDirection(GPIOC, BTN_0, ePinDir_Input);
  setPinFunction(PORTC, BTN_0, eAF_pinGPIO);
  setPinPasiveFilter(PORTC, BTN_0, ePasFilter_On);

  setPinIntrerrupt(GPIOC, BTN_0, IRQC_RE);

  setPinDirection(GPIOC, BTN_1, ePinDir_Input);
  setPinFunction(PORTC, BTN_1, eAF_pinGPIO);
  setPinPasiveFilter(PORTC, BTN_1, ePasFilter_On);

  setPinIntrerrupt(GPIOC, BTN_1, IRQC_RE);

  whichLED = LED_RED;

  for(;;)
  {
	leftButPressState = isPressed(eButtonLeft);
	rightButPressState = isPressed(eButtonRight);

	if( eBtn_Pressed == leftButPressState)
	{
		switch(whichLED)
		{
		case LED_BLUE:
			whichLED = LED_RED;
			break;
		case LED_RED:
			whichLED = LED_GREEN;
			break;
		default:
			whichLED = LED_BLUE;
		}

		waitButtonRelease(eButtonLeft);
	}

	if( eBtn_LongPress == rightButPressState )
	{
		switch(whichLED)
		{
		case LED_BLUE:
			factorB += 5;
			cpuDelayMs(100);
			if (factorB > 255)
				factorB = 0;
			break;
		case LED_RED:
			factorR += 5;
			cpuDelayMs(100);
			if (factorR > 255)
				factorR = 0;
			break;
		default:
			factorG += 5;
			cpuDelayMs(100);
			if (factorG > 255)
				factorG = 0;
			cpuDelayMs(100);
		}
	}
	else if( eBtn_Pressed == rightButPressState )
	{
		switch(whichLED)
		{
		case LED_BLUE:
			factorB += 30;
			if (factorB > 255)
				factorB = 0;
			break;
		case LED_RED:
			factorR += 30;
			if (factorR > 255)
				factorR = 0;
			break;
		default:
			factorG += 30;
			if (factorG > 255)
				factorG = 0;
		}
	}

	switch(whichLED)
	{
	case LED_BLUE:
		setPWMDUty(FTM0, ePWMLED_GREEN, 0);
		setPWMDUty(FTM0, ePWMLED_BLUE, factorB);
		cpuDelayMs(100);
		break;
	case LED_RED:
		setPWMDUty(FTM0, ePWMLED_BLUE, 0);
		setPWMDUty(FTM0, ePWMLED_RED, factorR);
		cpuDelayMs(100);
		break;
	default:
		setPWMDUty(FTM0, ePWMLED_RED, 0);
		setPWMDUty(FTM0, ePWMLED_GREEN, factorG);
		cpuDelayMs(100);
	}
  }
}
