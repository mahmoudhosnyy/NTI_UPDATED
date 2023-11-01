/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 24 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

										/***** TIMER0 *****/					
void TIMER0_VoidInit(void);
void TIMER0_VoidStop(void);
void TIMER0_VoidStart(void);
void TIMER0_VoidSetPreload(u8 copy_u8PRELOAD);
u8 TIMER0_VoidVal(void);
void TIMER_voidSetCallBack(void (*ptr_timer)(void));

/* Polling Delay function */
void TIMER0_voidDelay_ms(u32 Local_u32Delay);

void TIMER0_VoidSetPWMCompareMatch(u8 copy_u8Val );

void WDT_VoidEnable(void);
void WDT_VoidDisEnable(void);
void WDT_VoidSleep(u8 sleep_time);

										/***** TIMER1 ******/
									
typedef enum
{
	OCRA_DISCONNECTED			= 0b00,
	OCRA_TOGGLE					= 0b01,
	OCRA_NON_INVERTING			= 0b10,
	OCRA_INVERTING				= 0b11

}OC1A_MODE_TYPE;
										
typedef enum
{
	OCRB_DISCONNECTED			= 0b00,
	OCRB_TOGGLE					= 0b01,
	OCRB_NON_INVERTING			= 0b10,
	OCRB_INVERTING				= 0b11

}OC1B_MODE_TYPE;										

void TIMER1_voidInit(void);
void TIMER1_voidOCRA1Mode(OC1A_MODE_TYPE OC1A_Mode);
void TIMER1_voidOCRB1Mode(OC1B_MODE_TYPE OC1B_Mode);

/*
void TIMER1_ICU_InterruptEnable(void);
void TIMER1_ICU_InterruptDisable(void);
void Timer1_InputCaptureEdge(ICU_Edge_type edge);
void TIMER1_ICU_SetCallBack(void(*LocalFptr)(void));

*/
void TIMER1_OVF_InterruptEnable(void);
void TIMER1_OVF_InterruptDisable(void);

void TIMER1_OCA_InterruptEnable(void);
void TIMER1_OCA_InterruptDisable(void);

void TIMER1_OCB_InterruptEnable(void);
void TIMER1_OCB_InterruptDisable(void);

void TIMER1_voidSetCallBackOVF(void(*Local_PTF)(void));
void TIMER1_voidSetCallBackOCA(void(*Local_PTF)(void));
void TIMER1_voidSetCallBackOCB(void(*Local_PTF)(void));

void TIMER1_voidSetOVFValue(u16 Local_OVFvalue);
void TIMER1_voidSetOCRAValue(u16 Local_OCRAvalue);
void TIMER1_voidSetOCRBValue(u16 Local_OCRBvalue);

#endif
