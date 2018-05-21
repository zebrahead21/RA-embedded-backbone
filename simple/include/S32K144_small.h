/*Very simple include file with only several definitions of the S32K144 MCU*/
/*09.05.2018 by ADiea for simplification of code base*/

#ifndef S32K144_SMALL_H
#define S32K144_SMALL_H

//From S32K144_features.h

/* @brief The 32-bit value used for unlocking the WDOG. */
#define FEATURE_WDOG_UNLOCK_VALUE                       (0xD928C520U)
/* @brief The value used to set WDOG source clock from LPO. */
#define FEATURE_WDOG_CLK_FROM_LPO                       (0x1UL)

//we are on a 32bit arch so unsigned int should be a uint32
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

//From S32K144.h

//############################ Watchdog definitions ############################

/** WDOG - Register Layout Typedef */
typedef struct {
   uint32_t CS;                                /**< Watchdog Control and Status Register, offset: 0x0 */
   uint32_t CNT;                               /**< Watchdog Counter Register, offset: 0x4 */
   uint32_t TOVAL;                             /**< Watchdog Timeout Value Register, offset: 0x8 */
   uint32_t WIN;                               /**< Watchdog Window Register, offset: 0xC */
} WDOG_Type, *WDOG_MemMapPtr;

/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG base address */
#define WDOG_BASE                                (0x40052000u)
/** Peripheral WDOG base pointer */
#define WDOG                                     ((WDOG_Type *)WDOG_BASE)

#define WDOG_CS_CLK_SHIFT                        8u
#define WDOG_CS_CMD32EN_SHIFT                    13u
#define WDOG_CS_EN_SHIFT                         7u
#define WDOG_CS_UPDATE_SHIFT                     5u

//############################ peripheral enable definitions ############################

typedef struct {
	uint8_t RESERVED_0[128];
	uint32_t FTFC;
	uint32_t DMAMUX;
	uint8_t RESERVED_1[8];
	uint32_t FlexCAN0;
	uint32_t FlexCAN1;
	uint32_t FTM3;
	uint32_t ADC1;
	uint8_t RESERVED_2[12];
	uint32_t FlexCAN2;
	uint32_t LPSPI0;
	uint32_t LPSPI1;
	uint32_t LPSPI2;
	uint8_t RESERVED_3[8];
	uint32_t PDB1;
	uint32_t CRC;
	uint8_t RESERVED_4[12];
	uint32_t PDB0;
	uint32_t LPIT;
	uint32_t FTM0;
	uint32_t FTM1;
	uint32_t FTM2;
	uint32_t ADC0;
	uint8_t RESERVED_5[4];
	uint32_t RTC;
	uint8_t RESERVED_6[8];
	uint32_t LPTMR0;
	uint8_t RESERVED_7[32];
	uint32_t PORTA_CLK;
	uint32_t PORTB_CLK;
	uint32_t PORTC_CLK;
	uint32_t PORTD_CLK;
	uint32_t PORTE_CLK;
	uint8_t RESERVED_8[24];
	uint32_t SAI0;
	uint32_t SAI1;
	uint8_t RESERVED_9[16];
	uint32_t FlexIO;
	uint8_t RESERVED_10[24];
	uint32_t EWM;
	uint8_t RESERVED_11[16];
	uint32_t LPI2C0;
	uint32_t LPI2C1;
	uint8_t RESERVED_12[8];
	uint32_t LPUART0;
	uint32_t LPUART1;
	uint32_t LPUART2;
	uint8_t RESERVED_13[4];
	uint32_t FTM4;
	uint32_t FTM5;
	uint32_t FTM6;
	uint32_t FTM7;
	uint8_t RESERVED_14[4];
	uint32_t CMP0;
	uint8_t RESERVED_15[8];
	uint32_t QSPI;
	uint8_t RESERVED_16[8];
	uint32_t ENET;

} PCC_Type, *PCC_MemMapPtr;

/** Peripheral PCC base address */
#define PCC_BASE                                 (0x40065000u)
/** Peripheral PCC base pointer */
#define PCC                                      ((PCC_Type *)PCC_BASE)

#define PCC_PCCn_CGC_MASK                        (1<<30)

//############################ GPIO(general purpose input/output) enable definitions ############################

/** GPIO - Register Layout Typedef */
typedef struct {
	uint32_t PDOR;                              /**< Port Data Output Register, offset: 0x0 */
    uint32_t PSOR;                              /**< Port Set Output Register, offset: 0x4 */
    uint32_t PCOR;                              /**< Port Clear Output Register, offset: 0x8 */
    uint32_t PTOR;                              /**< Port Toggle Output Register, offset: 0xC */
    uint32_t PDIR;                              /**< Port Data Input Register, offset: 0x10 */
    uint32_t PDDR;                              /**< Port Data Direction Register, offset: 0x14 */
    uint32_t PIDR;                              /**< Port Input Disable Register, offset: 0x18 */
} GPIO_Type, *GPIO_MemMapPtr;


/** Peripheral PTD base address */
#define GPIOA_BASE                                 (0x400FF000u)
/** Peripheral PTD base pointer */
#define GPIOA                                      ((GPIO_Type *)GPIOA_BASE)


/** Peripheral PTD base address */
#define GPIOB_BASE                                 (0x400FF040u)
/** Peripheral PTD base pointer */
#define GPIOB                                      ((GPIO_Type *)GPIOB_BASE)


/** Peripheral PTC base address */
#define GPIOC_BASE                                 (0x400FF080u)
/** Peripheral PTC base pointer */
#define GPIOC                                    ((GPIO_Type *)GPIOC_BASE)


/** Peripheral PTD base address */
#define GPIOD_BASE                                 (0x400FF0C0u)
/** Peripheral PTD base pointer */
#define GPIOD                                      ((GPIO_Type *)GPIOD_BASE)


/** Peripheral PTE base address */
#define GPIOE_BASE                                 (0x400FF100u)
/** Peripheral PTD base pointer */
#define GPIOE                                      ((GPIO_Type *)GPIOE_BASE)


/*GPIO Pins*/
/*
 * 18 Pins on PORTA
 * 18 Pins on PORTB
 * 18 Pins on PORTC
 * 18 Pins on PORTD
 * 18 Pins on PORTE
 */

#define GPIO_Pin_0                 0 /*!< Pin 0 selected */
#define GPIO_Pin_1                 1  /*!< Pin 1 selected */
#define GPIO_Pin_2                 2  /*!< Pin 2 selected */
#define GPIO_Pin_3                 3  /*!< Pin 3 selected */
#define GPIO_Pin_4                 4  /*!< Pin 4 selected */
#define GPIO_Pin_5                 5  /*!< Pin 5 selected */
#define GPIO_Pin_6                 6  /*!< Pin 6 selected */
#define GPIO_Pin_7                 7  /*!< Pin 7 selected */
#define GPIO_Pin_8                 8  /*!< Pin 8 selected */
#define GPIO_Pin_9                 9  /*!< Pin 9 selected */
#define GPIO_Pin_10                10  /*!< Pin 10 selected */
#define GPIO_Pin_11                11  /*!< Pin 11 selected */
#define GPIO_Pin_12                12  /*!< Pin 12 selected */
#define GPIO_Pin_13                13  /*!< Pin 13 selected */
#define GPIO_Pin_14                14  /*!< Pin 14 selected */
#define GPIO_Pin_15                15  /*!< Pin 15 selected */
#define GPIO_Pin_16                16  /*!< Pin 16 selected */
#define GPIO_Pin_17                17  /*!< Pin 17 selected */



/** PORT - Size of Registers Arrays */
#define PORT_PCR_COUNT                           32u

/** PORT - Register Layout Typedef */
typedef struct {
	uint32_t PCR[PORT_PCR_COUNT];               /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
    uint32_t GPCLR;                             /**< Global Pin Control Low Register, offset: 0x80 */
    uint32_t GPCHR;                             /**< Global Pin Control High Register, offset: 0x84 */
    uint8_t RESERVED_0[24];
    uint32_t ISFR;                              /**< Interrupt Status Flag Register, offset: 0xA0 */
    uint8_t RESERVED_1[28];
    uint32_t DFER;                              /**< Digital Filter Enable Register, offset: 0xC0 */
    uint32_t DFCR;                              /**< Digital Filter Clock Register, offset: 0xC4 */
    uint32_t DFWR;                              /**< Digital Filter Width Register, offset: 0xC8 */
} PORT_Type, *PORT_MemMapPtr;


/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE                               (0x40049000u)
/** Peripheral PORTA base pointer */
#define PORTA                                    ((PORT_Type *)PORTA_BASE)

/** Peripheral PORTB base address */
#define PORTB_BASE                               (0x4004A000u)
/** Peripheral PORTB base pointer */
#define PORTB                                    ((PORT_Type *)PORTB_BASE)

/** Peripheral PORTC base address */
#define PORTC_BASE                               (0x4004B000u)
/** Peripheral PORTC base pointer */
#define PORTC                                    ((PORT_Type *)PORTC_BASE)

/** Peripheral PORTD base address */
#define PORTD_BASE                               (0x4004C000u)
/** Peripheral PORTD base pointer */
#define PORTD                                    ((PORT_Type *)PORTD_BASE)

/** Peripheral PORTE base address */
#define PORTE_BASE                               (0x4004D000u)
/** Peripheral PORTE base pointer */
#define PORTE                                    ((PORT_Type *)PORTE_BASE)

/*Interrupt Configuration*/
typedef enum{
	/*ISF flag and DMA request on rising edge */
	IRQC_DMA_RE = 1,
	/*ISF flag and DMA request on falling edge */
	IRQC_DMA_FE	= 2,
	/*ISF flag and DMA request on either edge */
	IRQC_DMA_EE = 3,
	/*ISF flag ad Interrupt when logic 0*/
	IRQC_L0		= 8,
	/*ISF flag ad Interrupt on rising edge*/
	IRQC_RE		= 9,
	/*ISF flag ad Interrupt on falling edge*/
	IRQC_FE		= 10,
	/*ISF flag ad Interrupt on either edge*/
	IRQC_EE		= 11,
	/*ISF flag ad Interrupt when logic 1*/
	IRQC_L1		= 12

}IRQ_Config;

/*Lock Register*/
#define PCR_LK			15

/*Pin Mux Control*/
#define PCR_MUX			 8

/*Pin Configuration Mux */
typedef enum {
	AFIO_DSBL,
	AFIO_GPIO,
	AFIO_2,
	AFIO_3,
	AFIO_4,
	AFIO_5,
	AFIO_6,
	AFIO_7
} AFIO;

/*Drive Strength Enable */
#define	PCR_DSR			 6

/*Passive Filter Enable */
#define PCR_PFE			 4

/*Pull Enable*/
#define PCR_PE			 1

/*Pull Select */
#define PCR_PS			 0


#endif
