/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 21 Oct 2023				*/
/* Version : V01                        */
/****************************************/
#include <util\delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LCD_interface.h"
#include "KEYPAD_interface.h"

void main(void){
	KEYPAD_init();
	LCD_init();
	u8 get_key;
	while (1){
		get_key=KEYPAD_getPressedKey();
		if(get_key=='1'){
			LCD_displayStringRowColumn(0,0,"Mahmoud");
		}
		else if(get_key=='2'){
			LCD_displayStringRowColumn(1,0,"Hosny");
		}
		else if(get_key=='3'){
			LCD_displayStringRowColumn(2,0,"Abozaid");
		}
		else if(get_key=='4'){
			LCD_clearScreen();
		} 
	}
	
}
