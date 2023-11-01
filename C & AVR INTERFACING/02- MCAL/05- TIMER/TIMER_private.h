/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 24 Oct 2023				*/
/* Version : V01                        */
/****************************************/
 
#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/************************************* TIMER0 & TIMER1 & TIMER2  GENERAL REGS ***********************************************/

typedef struct
{
	u8 TOIE0	: 1;
	u8 OCIE0	: 1;
	u8 TOIE1	: 1;
	u8 OCIE1B	: 1;
	u8 OCIE1A	: 1;
	u8 TICIE1	: 1;
	u8			: 2;

}TIMSK;
#define TIMSK_Reg		((volatile TIMSK *)0x59)

/*******************************************************/

typedef struct
{
	u8 TOV0		: 1;
	u8 OCF0		: 1;
	u8 TOV1		: 1;
	u8 OCF1B	: 1;
	u8 OCF1A	: 1;
	u8 ICF1		: 1;
	u8			: 2;

}TIFR;
#define TIFR_Reg		((volatile TIFR *)0x58)
/*******************************************************/




/************************************* TIMER0 ***********************************************/

/*******************************************************/
#define TCNT0_Reg		*((volatile u8 *)0x52)
#define OCR0_Reg			*((volatile u8 *)0x5C)
/*******************************************************/
typedef struct
{
	u8 CS0 		: 3;
	u8 WGM01 	: 1;
	u8 COM0		: 2;
	u8 WGM00	: 1;
	u8 FOC0		: 1;
}TCCR0;
#define TCCR0_Reg		((volatile TCCR0 *)0x53)

typedef enum
{
	TIMER_0_NO_CLOCK	 			= 0b000,
	TIMER_0_NO_PRESCALER			= 0b001,
	TIMER_0_PRESCALER_8				= 0b010,
	TIMER_0_PRESCALER_64			= 0b011,
	TIMER_0_PRESCALER_265			= 0b100,
	TIMER_0_PRESCALER_1024			= 0b101,
	TIMER_0_EXT_CLK_SRC_FALING_EDGE = 0b110,
	TIMER_0_EXT_CLK_SRC_RISING_EDGE = 0b111
}TIMER_0_PRESCALER_SELECT;

/* Bits WGM01 WGM00 at Reg TCCR0*/
#define	Normal_MODE 	 			0b00
#define	PWM__PHASE_CORRECT_MODE		0b01
#define	CTC_MODE					0b10
#define	FAST_PWM_MODE				0b11
/* Bits COM01 COM00 at Reg TCCR0*/
#define	OC0_DISCONNECTED			0b00
#define NON_INVERTING_MODE			0b10
#define INVERITNG_MODE				0b11
/*******************************************************/





/************************************* TIMER1 ***********************************************/
#define TCNT1L_Reg		*((volatile u8 *)0x4C)
#define TCNT1H_Reg		*((volatile u8 *)0x4D)
#define TCNT1_Reg		*((volatile u16 *)0x4C)

#define ICR1L_Reg		*((volatile u8 *)0x46)
#define ICR1H_Reg		*((volatile u8 *)0x47)
#define ICR1_Reg			*((volatile u16 *)0x46)
/*******************************************************/

typedef struct
{
	u8 CS		: 3;
	u8 OCIE0	: 1;
	u8 WGM123	: 2;
	u8			: 1;
	u8 ICES1	: 1;
	u8 ICNC1	: 1;

}TCCR1B;
#define TCCR1B_Reg		((volatile TCCR1B *)0x4E)

/*	Select in CS12 CS11 CS10 in TCCR1B	*/
typedef enum
{
	TIMER_1_NO_CLOCK	 			= 0b000,
	TIMER_1_NO_PRESCALER			= 0b001,
	TIMER_1_PRESCALER_8				= 0b010,
	TIMER_1_PRESCALER_64			= 0b011,
	TIMER_1_PRESCALER_265			= 0b100,
	TIMER_1_PRESCALER_1024			= 0b101,
	TIMER_1_EXT_CLK_SRC_FALING_EDGE = 0b110,
	TIMER_1_EXT_CLK_SRC_RISING_EDGE = 0b111
}TIMER1_PRESCALER_SELECT;

/*******************************************************/
typedef struct
{
	u8 WGM101	: 2;
	u8 FOC1B	: 1;
	u8 FOC1A	: 1;
	u8 COM1B	: 2;
	u8 COM1A	: 2;
}TCCR1A;

#define TCCR1A_Reg		((volatile TCCR1A *)0x4F)

/* Bits WGM13 WGM12 in TCCR1B & WGM11 WGM10 in TCCR1A*/
#define	TIMER1_NORMAL_MODE 	 				0b0000		//Top = 0xFFFF
#define	TIMER1_PWM_PHASECORRECT_8BIT		0b0001		//Top = 0x00FF
#define	TIMER1_PWM_PHASECORRECT_9BIT		0b0010		//Top = 0x01FF
#define	TIMER1_PWM_PHASECORRECT_10BIT		0b0011		//Top = 0x03FF
#define TIMER1_CTC_MODE						0b0100		//On OCR1A
#define	TIMER1_FAST_PWM_8BIT				0b0101      //Top = 0x00FF
#define	TIMER1_FAST_PWM_9BIT				0b0110      //Top = 0x01FF
#define	TIMER1_FAST_PWM_10BIT				0b0111      //Top = 0x03FF
#define	TIMER1_FAST_PWM						0b1110      //Top = ICR1

/*******************************************************/

#define OCR1AL_Reg		*((volatile u8 *)0x4A)
#define OCR1AH_Reg		*((volatile u8 *)0x4B)
#define OCR1A_Reg		*((volatile u16 *)0x4A)
/*******************************************************/
#define OCR1BL_Reg		*((volatile u8 *)0x48)
#define OCR1BH_Reg		*((volatile u8 *)0x49)
#define OCR1B_Reg		*((volatile u16 *)0x48)
/*******************************************************/

#endif
