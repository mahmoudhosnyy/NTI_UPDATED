/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 27 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

#define NORMAL_MODE 0
#define PWM_PHASE_CORRECT_MODE 1
#define CTC_MODE 2
#define FAST_PWM_MODE 3
/*********************************************************************/
typedef struct {
	u8 CS:3;
	u8 WGM01:1;
	u8 COM:2;
	u8 WGM00:1;
	u8 FOC0:1;
}TCCR0;

#define TCCR0_Reg  ((volatile TCCR0*)0x53)

/** Clock SELECTION **/
enum CLOCK_SELECT {
	STOP_TIMER=0b000,
	NO_PRESCALAR=0b001,
	PRESCALAR_DIV_FACTOR_8=0b010,
	PRESCALAR_DIV_FACTOR_64=0b011,
	PRESCALAR_DIV_FACTOR_256=0b100,
	PRESCALAR_DIV_FACTOR_1024=0b101,
	EXTERNAL_SOURCE_ON_FALLING_EDGE=0b110,
	EXTERNAL_SOURCE_ON_RISING_EDGE=0b111
};

/** COMPARE OUTPUT MODE - NON PWM **/
#define	NORMAL_OPERATION_OC0_DISCONNECTED 0b00
#define	TOGGLE_OC0_ON_COMPARE_MATCH 0b01
#define	CLEAR_OC0_ON_COMPARE_MATCH 0b10
#define	SET_OC0_ON_COMPARE_MATCH 0b11


/** COMPARE OUTPUT MODE - FAST PWM  **/
#define NORMAL_OC0_DISCONNECTED_ 0b00
#define CLEAR_OC0_ON_COMPARE 0b10
#define SET_OC0_ON_COMPARE  0b11

/** COMPARE OUTPUT MODE - PHASE CORRECT PWM **/
#define	NORMAL_OPERATION_OC0_DISCONNECTED__ 0b00
#define CLEAR_OC0_ON_UPCOUNTING_COMPARE_MATCH_SET_OC0_ON_DOWNCOUNTING 0b10
#define SET_OC0_ON_UPCOUNTING_COMPARE_MATCH_CLEAR_OC0_ON_DOWNCOUNTING 0b11


/*********************************************************************/
#define TCNT0_Reg  *((volatile u8*)0x52)
/*********************************************************************/
#define OCR0_Reg  *((volatile u8*)0x5C)
/*********************************************************************/

typedef struct {
	u8 TOIE0:1;
	u8 OCIE0:1;
	u8 TOIE1:1;
	u8 OCIE1B:1;
	u8 OCIE1A:1;
	u8 TICIE1:1;
	u8  :2;
}TIMSK;

#define TIMSK_Reg       ((volatile TIMSK*)0x59)

#define TIMER_COMPARE_MATCH_INTERRUPT_ENABLE 0b1
#define TIMER_COMPARE_MATCH_INTERRUPT_DISABLE 0b0
#define TIMER_OVERFLOW_INTERRUPT_ENABLE 0b1
#define TIMER_OVERFLOW_INTERRUPT_DISABLE 0b0
/*********************************************************************/

typedef struct {
	u8 TOV0:1;
	u8 OCF0:1;
	u8 TOV1:1;
	u8 OCF1B:1;
	u8 OCF1A:1;
	u8 ICF1:1;
	u8 :2;
}TIFR;

#define TIFR_Reg       ((volatile TIFR*)0x58)

#define CLEAR_TIMER_OUTPUT_COMPARE_FLAG 0b1
#define CLEAR_TIMER_OVERFLOW_FLAG 0b1
/*********************************************************************/

typedef struct {
	u8 WGM10 : 1;
	u8 WGM11 : 1;
	u8 FOC1B : 1;
	u8 FOC1A : 1;
	u8 COM1B :2;
	u8 COM1A :2;	
}TCCR1A;

#define TCCR1A_Reg     ((volatile TCCR1A*)0x58)

/*********************************************************************/

typedef struct {
	u8 CS1 :3 ;
	u8 FOC1A : 1;
	u8 COM1B :2;
	u8 COM1A :2;
	u8 WGM12 :1;
	u8 WGM13 :1;
	u8  :1;
	u8 ICES1:1;
	u8 ICNC1:1;
}TCCR1B;

#define TCCR1B_Reg     ((volatile TCCR1B*)0x58)


/*********************************************************************/
#define TCTNT1L_Reg        *((volatile u8*)0x58)  
#define TCTNT1H_Reg        *((volatile u8*)0x58)
#define TCTNT1_Reg 		   *((volatile u16*)0x58)

#define OCR1AL_Reg         *((volatile u8*)0x58)    
#define OCR1AH_Reg         *((volatile u8*)0x58) 
#define OCR1A_Reg		   *((volatile u16*)0x58) 

#define OCR1BL_Reg         *((volatile u8*)0x58)    
#define OCR1BH_Reg         *((volatile u8*)0x58)
#define OCR1B_Reg		   *((volatile u16*)0x58)

#define ICR1


#endif