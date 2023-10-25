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

void main(void){
	LCD_init();
	while (1){
	LCD_displayStringRowColumn(0,0,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(1,1,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(2,2,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(3,3,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,4,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(1,5,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(2,6,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(3,7,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,8,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(1,9,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(2,10,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(3,11,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,12,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(1,13,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(2,14,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(3,15,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,16,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(1,17,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(2,18,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(3,19,"m");
	_delay_ms(1000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,20,"m");
	_delay_ms(1000);
	LCD_clearScreen();	
	}
}
