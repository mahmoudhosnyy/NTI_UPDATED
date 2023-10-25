/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 20 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"


#include "DIO_interface.h"

void LED_init (void) {
	DIO_SetPinDirection(PORTB,PIN7,OUTPUT);
	DIO_SetPinDirection(PORTA,PIN4,OUTPUT);	
	DIO_SetPinDirection(PORTA,PIN5,OUTPUT);	
	DIO_SetPinDirection(PORTA,PIN6,OUTPUT);	
}

void LED_on(u8 led_colour){
	switch (led_colour){
		case LED_RED :
			DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
		break;
		case LED_GREEN :
			DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,HIGH);
		break;
		case LED_BLUE :
			DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,HIGH);
		break;
		case LED_YELLOW :
			DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,HIGH);
		break;		
	}
}

void LED_off(u8 led_colour){
	switch (led_colour){
		case LED_RED :
			DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,LOW);
		break;
		case LED_GREEN :
			DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,LOW);
		break;
		case LED_BLUE :
			DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,LOW);
		break;
		case LED_YELLOW :
			DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,LOW);
		break;		
	}
}

void LED_ALL_OFF(void){
	DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,LOW);
	DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,LOW);
	DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,LOW);
	DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,LOW);
}

void LED_ALL_ON(void){
	DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
	DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,HIGH);
	DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,HIGH);
	DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,HIGH);
}


void LED_binary(u8 num){
	switch (num){
		case 0 : 
		LED_ALL_OFF();
		break;
		case 1 :
		DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
	    DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,LOW);
	    DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,LOW);
	    DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,LOW);
		break;
		case 2 :
		DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,LOW);
	    DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,HIGH);
	    DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,LOW);
	    DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,LOW);
		break;		
		case 3 :
		DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
	    DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,HIGH);
	    DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,LOW);
	    DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,LOW);
		break;
		case 4 :
		DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,LOW);
	    DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,LOW);
	    DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,HIGH);
	    DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,LOW);
		break;
		case 5 :
		DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
	    DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,LOW);
	    DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,HIGH);
	    DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,LOW);
		break;
		case 6 :
		DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,LOW);
	    DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,HIGH);
	    DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,HIGH);
	    DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,LOW);
		break;
		case 7 :
		DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
	    DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,HIGH);
	    DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,HIGH);
	    DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,LOW);
		break;
		case 8 :
		DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,LOW);
	    DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,LOW);
	    DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,LOW);
	    DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,HIGH);
		break;
		case 9 :
		DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
	    DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,LOW);
	    DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,LOW);
	    DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,HIGH);
		break;
		case 10 :
		DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,LOW);
	    DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,HIGH);
	    DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,LOW);
	    DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,HIGH);
		break;
		case 11 :
		DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
	    DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,HIGH);
	    DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,LOW);
	    DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,HIGH);
		break;
		case 12 :
		DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,LOW);
	    DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,LOW);
	    DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,HIGH);
	    DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,HIGH);
		break;
		case 13 :
		DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
	    DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,LOW);
	    DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,HIGH);
	    DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,HIGH);
		break;
		case 14 :
		DIO_SetPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
	    DIO_SetPinValue(LED_GREEN_PORT,LED_GREEN_PIN,HIGH);
	    DIO_SetPinValue(LED_BLUE_PORT,LED_BLUE_PIN,HIGH);
	    DIO_SetPinValue(LED_YELLOW_PORT,LED_YELLOW_PIN,HIGH);
		break;
		case 15 :
		LED_ALL_ON();
		break;
	}
}