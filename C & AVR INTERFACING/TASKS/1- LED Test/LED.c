/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 20 Oct 2023				*/
/* Version : V01                        */
/****************************************/
#include <util\delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "SEVENSEG_interface.h"


void main(void){
	LED_init();
	SEVENSEG_init();
	
	while (1){
		
		for (u8 u8_numCounter=0; u8_numCounter<=9; u8_numCounter++){
		SEVENSEG_displayNum(u8_numCounter);
		}
		
		LED_on(LED_RED);
		_delay_ms(1000);
		LED_off(LED_RED);
		
		LED_on(LED_GREEN);
		_delay_ms(1000);
		LED_off(LED_GREEN);

		LED_on(LED_BLUE);
		_delay_ms(1000);
		LED_off(LED_BLUE);
		
		LED_on(LED_YELLOW);
		_delay_ms(1000);
		LED_off(LED_YELLOW);
	}
	
	
	
}