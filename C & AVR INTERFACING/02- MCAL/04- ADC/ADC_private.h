/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 24 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/***********************************************/
typedef struct {
	u8 MUX:5;
	u8 ADLAR:1;
	u8 REFS:2;
}ADMUX; 

/** ADLAR SELECTION **/
#define ADJUST_RIGHT 0x00
#define ADJUST_LEFT 0x01

/** REFERENCE SELECTION **/
enum VOLTAGE_REFERENCE_SELECTION{
	AREF=0b00,
	AVCC=0b01,
	INTERNAL=0b11
};

#define ADMUX_Reg  ((volatile ADMUX*)0x27)
/************************************************/
typedef struct {
	u8 ADPS:3 ;
	u8 ADIE:1 ;
	u8 ADIF:1 ;
	u8 ADATE:1;
	u8 ADSC:1;
	u8 ADEN:1;
}ADCSRA;

/** ADPS SELECTION **/
enum PRESCALAR_SELECTION{
	DIV_FACTOR_2=0b001,
	DIV_FACTOR_4=0b010,
	DIV_FACTOR_8=0b011,
	DIV_FACTOR_16=0b100,
	DIV_FACTOR_32=0b101,
	DIV_FACTOR_64=0b110,
	DIV_FACTOR_128=0b111
};

#define ADC_INTERRUPT_ENABLE 0b1
#define ADC_INTERRUPT_FLAG_CLEAR 0b1
#define ADC_ENABLE_TRIGGER 0b1
#define ADC_DISABLE_TRIGGER 0b0
#define ADC_START_CONVERSION 0b1
#define ADC_ENABLE 0b1
#define ADC_DISABLE 0b0

#define ADCSRA_Reg  ((volatile ADCSRA*)0x26)
/*************************************************/
typedef struct {
	u8  :5 ;
	u8 ADTS:3 ;
}SFIOR;

/** ADTS SELECTION **/
enum  TRIGGER_SOURCE_SELECTION{
	FREE_RUNNING_MODE=0b000,
	ANALOG_COMPARATOR_MODE=0b001,
	EXTERNAL_INTERRUPT_MODE=0b010,
	TIMER0_COMPARE_MATCH_MODE=0b011,
	TIMER0_OVERFLOW_MODE=0b100,
	TIMER_COMPARE_MATCH_B_MODE=0b101,
	TIMER1_OVERFLOW_MODE=0b110,
	TIMER1_CAPTURE_EVENT=0b111	
};

#define SFIOR_Reg  ((volatile SFIOR*)0x50)
/*************************************************/

/** ADC DATA **/
#define ADCL_Reg  *((volatile u8*)0x24)   
#define ADCH_Reg  *((volatile u8*)0x25)
#define ADC_DATA_Reg  *((volatile u16*)0x24)

#endif