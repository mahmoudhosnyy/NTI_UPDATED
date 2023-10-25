/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 20 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SEVENSEG_interface.h"
#include "SEVENSEG_config.h"
#include "SEVENSEG_private.h"

#include "DIO_interface.h"

void SEVENSEG_init(void){
	/* SET DIRECTIONS FOR 7SEG & DIP_SWTICH */
	DIO_SetPinDirection(PORTB,PIN0,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN1,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN2,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN4,OUTPUT);
	
	DIO_SetPinDirection(PORTA,PIN3,OUTPUT);
	DIO_SetPinDirection(PORTA,PIN2,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN5,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN6,OUTPUT);
}

void SEVENSEG_displayNum(u8 num,u8 com_num){
	if (com_num==COM1){
	DIO_SetPinValue(PORTA,PIN3,LOW);
	DIO_SetPinValue(PORTA,PIN2,HIGH);	
	DIO_SetPinValue(PORTB,PIN5,HIGH);	
	DIO_SetPinValue(PORTB,PIN6,HIGH);
	}
	else if (com_num==COM2){
	DIO_SetPinValue(PORTA,PIN3,HIGH);
	DIO_SetPinValue(PORTA,PIN2,LOW);	
	DIO_SetPinValue(PORTB,PIN5,HIGH);	
	DIO_SetPinValue(PORTB,PIN6,HIGH);
	}
	else if (com_num==COM3){
	DIO_SetPinValue(PORTA,PIN3,HIGH);
	DIO_SetPinValue(PORTA,PIN2,HIGH);	
	DIO_SetPinValue(PORTB,PIN5,LOW);	
	DIO_SetPinValue(PORTB,PIN6,HIGH);
	}
	else if (com_num==COM4){
	DIO_SetPinValue(PORTA,PIN3,HIGH);
	DIO_SetPinValue(PORTA,PIN2,HIGH);	
	DIO_SetPinValue(PORTB,PIN5,HIGH);	
	DIO_SetPinValue(PORTB,PIN6,LOW);
	}
	
	switch (num){
		case 0 :
		DIO_SetPinValue(PORTB,PIN0,LOW);
		DIO_SetPinValue(PORTB,PIN1,LOW);
		DIO_SetPinValue(PORTB,PIN2,LOW);
		DIO_SetPinValue(PORTB,PIN4,LOW);
		break;
		case 1 :
		DIO_SetPinValue(PORTB,PIN0,HIGH);
		DIO_SetPinValue(PORTB,PIN1,LOW);
		DIO_SetPinValue(PORTB,PIN2,LOW);
		DIO_SetPinValue(PORTB,PIN4,LOW);
		break;
		case 2:
		DIO_SetPinValue(PORTB,PIN0,LOW);
		DIO_SetPinValue(PORTB,PIN1,HIGH);
		DIO_SetPinValue(PORTB,PIN2,LOW);
		DIO_SetPinValue(PORTB,PIN4,LOW);
		break;
		case 3:
		DIO_SetPinValue(PORTB,PIN0,HIGH);
		DIO_SetPinValue(PORTB,PIN1,HIGH);
		DIO_SetPinValue(PORTB,PIN2,LOW);
		DIO_SetPinValue(PORTB,PIN4,LOW);
		break;		
		case 4:
		DIO_SetPinValue(PORTB,PIN0,LOW);
		DIO_SetPinValue(PORTB,PIN1,LOW);
		DIO_SetPinValue(PORTB,PIN2,HIGH);
		DIO_SetPinValue(PORTB,PIN4,LOW);
		break;
		case 5:
		DIO_SetPinValue(PORTB,PIN0,HIGH);
		DIO_SetPinValue(PORTB,PIN1,LOW);
		DIO_SetPinValue(PORTB,PIN2,HIGH);
		DIO_SetPinValue(PORTB,PIN4,LOW);
		break;
		case 6:
		DIO_SetPinValue(PORTB,PIN0,LOW);
		DIO_SetPinValue(PORTB,PIN1,HIGH);
		DIO_SetPinValue(PORTB,PIN2,HIGH);
		DIO_SetPinValue(PORTB,PIN4,LOW);
		break;
		case 7:
		DIO_SetPinValue(PORTB,PIN0,HIGH);
		DIO_SetPinValue(PORTB,PIN1,HIGH);
		DIO_SetPinValue(PORTB,PIN2,HIGH);
		DIO_SetPinValue(PORTB,PIN4,LOW);
		break;
		case 8:
		DIO_SetPinValue(PORTB,PIN0,LOW);
		DIO_SetPinValue(PORTB,PIN1,LOW);
		DIO_SetPinValue(PORTB,PIN2,LOW);
		DIO_SetPinValue(PORTB,PIN4,HIGH);
		break;
		case 9:
		DIO_SetPinValue(PORTB,PIN0,HIGH);
		DIO_SetPinValue(PORTB,PIN1,LOW);
		DIO_SetPinValue(PORTB,PIN2,LOW);
		DIO_SetPinValue(PORTB,PIN4,HIGH);
		break;
	}	
}