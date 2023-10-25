#include <stdio.h>
#include <conio.h>

#include "DIO_interface.h"
#include "LED_interface.h"


void App(void){
	DIO_SetPinDirection(PORTD,PIN7,INPUT);
	if (DIO_GetPinValue==0){
		LED_on(LED_Red);
	}
	
	else {LED_off(LED_Red);}
	
	
}