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


void LED_SEVSEG(void){
	LED_init();
	SEVENSEG_init();

	LED_binary(0);
	SEVENSEG_displayNum(0);
	_delay_ms(1000);
	
	LED_binary(1);
	SEVENSEG_displayNum(1);
	_delay_ms(1000);
	
	LED_binary(2);
	SEVENSEG_displayNum(2);
	_delay_ms(1000);


	LED_binary(3);
	SEVENSEG_displayNum(3);
	_delay_ms(1000);
	
	LED_binary(4);
	SEVENSEG_displayNum(4);
	_delay_ms(1000);

	LED_binary(5);
	SEVENSEG_displayNum(5);
	_delay_ms(1000);
	
	LED_binary(6);
	SEVENSEG_displayNum(6);
	_delay_ms(1000);
	
	LED_binary(7);
	SEVENSEG_displayNum(7);
	_delay_ms(1000);
	
	LED_binary(8);
	SEVENSEG_displayNum(8);
	_delay_ms(1000);
	
	LED_binary(9);
	SEVENSEG_displayNum(9);
	_delay_ms(1000);
}