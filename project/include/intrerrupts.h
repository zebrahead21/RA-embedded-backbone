/*
 * intrerrupts.h
 *
 *  Created on: Jun 4, 2018
 *      Author: root
 */

#ifndef INTRERRUPTS_H_
#define INTRERRUPTS_H_


typedef struct {
	uint32_t NVIC_ISER0;
	uint32_t NVIC_ISER1;
	uint32_t NVIC_ISER2;
	uint32_t NVIC_ISER3;
	uint32_t NVIC_ISER4;
	uint32_t NVIC_ISER5;
	uint32_t NVIC_ISER6;
	uint32_t NVIC_ISER7;
} NVIC_ISER_Type, *Intrerrupts_Ser_MemMapPtr;

typedef struct {
	uint32_t NVIC_ICER0;
	uint32_t NVIC_ICER1;
	uint32_t NVIC_ICER2;
	uint32_t NVIC_ICER3;
	uint32_t NVIC_ICER4;
	uint32_t NVIC_ICER5;
	uint32_t NVIC_ICER6;
	uint32_t NVIC_ICER7;
} NVIC_ICER_Type, *Intrerrupts_Cer_MemMapPtr;

typedef struct {
	uint32_t NVIC_ISPR0;
	uint32_t NVIC_ISPR1;
	uint32_t NVIC_ISPR2;
	uint32_t NVIC_ISPR3;
	uint32_t NVIC_ISPR4;
	uint32_t NVIC_ISPR5;
	uint32_t NVIC_ISPR6;
	uint32_t NVIC_ISPR7;
} NVIC_ISPR_Type, *Intrerrupts_Ispr_MemMapPtr;

typedef struct {
	uint32_t NVIC_ICPR0;
	uint32_t NVIC_ICPR1;
	uint32_t NVIC_ICPR2;
	uint32_t NVIC_ICPR3;
	uint32_t NVIC_ICPR4;
	uint32_t NVIC_ICPR5;
	uint32_t NVIC_ICPR6;
	uint32_t NVIC_ICPR7;
} NVIC_ICPR_Type, *Intrerrupts_Icpr_MemMapPtr;

typedef struct {
	uint32_t NVIC_IABR0;
	uint32_t NVIC_IABR1;
	uint32_t NVIC_IABR2;
	uint32_t NVIC_IABR3;
	uint32_t NVIC_IABR4;
	uint32_t NVIC_IABR5;
	uint32_t NVIC_IABR6;
	uint32_t NVIC_IABR7;
} NVIC_IABR_Type, *Intrerrupts_Iabr_MemMapPtr;

typedef struct {
	uint32_t IPR[60];
}NVIC_IPR_Type, *Intrerrupts_Ipr_MemMapPtr;

#define NVIC_ISER_BASE                                 (0xE000E100u)
#define NVIC_ISER                                      ((NVIC_ISER_Type *)NVIC_ISER_BASE)

#define NVIC_ICER_BASE                                 (0xE000E180u)
#define NVIC_ICER                                      ((NVIC_ICER_Type *)NVIC_ICER_BASE)


#define NVIC_ISPR_BASE                                 (0xE000E200u)
#define NVIC_ISPR                                      ((NVIC_ISPR_Type *)NVIC_ISPR_BASE)


#define NVIC_ICPR_BASE                                 (0xE000E280u)
#define NVIC_ICPR                                      ((NVIC_ICPR_Type *)NVIC_ICPR_BASE)

#define NVIC_IABR_BASE                                 (0xE000E300u)
#define NVIC_IABR                                      ((NVIC_IABR_Type *)NVIC_IABR_BASE)


#define NVIC_IPR_BASE                                 (0xE000E400u)
#define NVIC_IPR                                      ((NVIC_IPR_Type *)NVIC_IPR_BASE)





#endif /* INTRERRUPTS_H_ */
