/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 21 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#include "util\delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

#include "DIO_interface.h"


void LCD_sendCommand(u8 command){
	//RS >> CLEAR (INSTRUCTION CODE)
	DIO_SetPinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOW);
	_delay_ms(1); /* page 6 in data sheet>> delay for processing Tas = 50ns */

	//RW >> SET TO GROUND IN EXERCISES ( WRITE INSTRUCTION ALWAYS)

	//EN >> HIGH >> DATA >> LOW
	DIO_SetPinValue(LCD_EN_PORT_ID,LCD_EN_PIN_ID,HIGH);
	_delay_ms(1); /* page 6 in data sheet>> delay for processing Tpw - Tdws = 190ns */
	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(command,4));
	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(command,5));
	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(command,6));
	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(command,7));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_SetPinValue(LCD_EN_PORT_ID,LCD_EN_PIN_ID,LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	DIO_SetPinValue(LCD_EN_PORT_ID,LCD_EN_PIN_ID,HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(command,0));
	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(command,1));
	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(command,2));
	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(command,3));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_SetPinValue(LCD_EN_PORT_ID,LCD_EN_PIN_ID,LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */


}


void LCD_init(void){
	DIO_SetPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,OUTPUT);
	DIO_SetPinDirection(LCD_EN_PORT_ID,LCD_EN_PIN_ID,OUTPUT);
	_delay_ms(20); // char comm pdf page 3 >> 20 ms to power on

	/* Configure 4 pins in the data port as output pins */
	DIO_SetPinDirection(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,OUTPUT);
	DIO_SetPinDirection(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,OUTPUT);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(0x33);
	LCD_sendCommand(0x32);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);


	/* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_DISPLAY); /* clear LCD at the beginning */

}


void LCD_displayCharacter(u8 data){
		DIO_SetPinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,HIGH); /* Data Mode RS=1 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	DIO_SetPinValue(LCD_EN_PORT_ID,LCD_EN_PIN_ID,HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(data,4));
	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(data,5));
	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(data,6));
	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(data,7));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_SetPinValue(LCD_EN_PORT_ID,LCD_EN_PIN_ID,LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	DIO_SetPinValue(LCD_EN_PORT_ID,LCD_EN_PIN_ID,HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(data,0));
	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(data,1));
	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(data,2));
	DIO_SetPinValue(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(data,3));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_SetPinValue(LCD_EN_PORT_ID,LCD_EN_PIN_ID,LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
}

void LCD_displayString(const char *Str){
	u8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
}

void LCD_moveCursor(u8 row,u8 col)
{
	u8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
		case 0:
			lcd_memory_address=col+0x80;
				break;
		case 1:
			lcd_memory_address=col+0xC0;
				break;
		case 2:
			lcd_memory_address=col+0x94;
				break;
		case 3:
			lcd_memory_address=col+0xD4;
				break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

void LCD_displayStringRowColumn(u8 row,u8 col,const char *Str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_DISPLAY); /* Send clear display command */
}

void LCD_intgerToString(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* stands for (integer to ascii) >> Use itoa C function to convert the data to its corresponding ASCII value,
   L 10 deh l radix y3ny l nzam l raqmy ele sh3'al 3aleh >> 10 for decimal ( nzaam 3ashry) ..
   law edeto 2 ysht3'l binary .. law edeto 8 ysht3'l octal w hakaza */

   /* note >> feh bardo atoi ( ascii to int ) w l etneen dool gowa stdlib.h */
   LCD_displayString(buff); /* Display the string */
}

