/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 22 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#include<util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"

#include "DIO_interface.h"

u8 KEYPAD_SYMBOLS[KEYPAD_NUM_ROWS][KEYPAD_NUM_COLS] = {{'1','2','3','+'},
													   {'4','5','6','-'},
												       {'7','8','9','*'},
												       {'C','0','=','/'}};
u8 COL_PORT_ARR[4]=COL_PORT_DATA;
u8 COL_PIN_ARR[4]=COL_PIN_DATA;
u8 ROW_PORT_ARR[4]=ROW_PORT_DATA;
u8 ROW_PIN_ARR[4]=ROW_PIN_DATA;

void KEYPAD_init(void){
	for (u8 row_counter=0;row_counter<KEYPAD_NUM_ROWS;row_counter++){
	DIO_SetPinDirection(ROW_PORT_ARR[row_counter],ROW_PIN_ARR[row_counter],OUTPUT);
	DIO_SetPinValue(ROW_PORT_ARR[row_counter],ROW_PIN_ARR[row_counter],HIGH);
	}
	
	for (u8 col_counter=0;col_counter<KEYPAD_NUM_COLS;col_counter++){
	DIO_SetPinDirection(COL_PORT_ARR[col_counter],COL_PIN_ARR[col_counter],INPUT);
	DIO_SetPinValue(COL_PORT_ARR[col_counter],COL_PIN_ARR[col_counter],HIGH);
	}
}

u8 KEYPAD_getPressedKey(void){
	u8 col_counter,row_counter,flag,key;
	
	for (row_counter=0;row_counter<KEYPAD_NUM_ROWS;row_counter++){
		DIO_SetPinValue(ROW_PORT_ARR[row_counter],ROW_PIN_ARR[row_counter],LOW);
		
		for (col_counter=0;col_counter<KEYPAD_NUM_COLS;col_counter++){
			if (DIO_GetPinValue(COL_PORT_ARR[col_counter],COL_PIN_ARR[col_counter])==0){
				//Debouncing delay
				_delay_ms(250);
				/*Polling until the button is released*/
				while (DIO_GetPinValue(COL_PORT_ARR[col_counter],COL_PIN_ARR[col_counter]) == 0);
				flag = 1;
				key= KEYPAD_SYMBOLS[row_counter][col_counter];
				break;
			}
		}
		DIO_SetPinValue(ROW_PORT_ARR[row_counter],ROW_PIN_ARR[row_counter],HIGH);
		if (flag == 1)
		{
			break;
		}
	}
	
return key;
}