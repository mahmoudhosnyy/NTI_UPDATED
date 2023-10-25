/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 21 Oct 2023				*/
/* Version : V01                        */
/****************************************/
#include <util\delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SEVENSEG_interface.h"
void main (void){
                       /* INITIALIZATION  */
	SEVENSEG_init();
	s8 seg1_counter=0;
	s8 seg2_counter=0;
	s8 seg3_counter=9;
	s8 seg4_counter=9;
	SEVENSEG_displayNum(seg1_counter,COM1);
	SEVENSEG_displayNum(seg2_counter,COM2);
	SEVENSEG_displayNum(seg3_counter,COM3);
	SEVENSEG_displayNum(seg4_counter,COM4);
	while (1){
		/* DISPLAYING NUMBERS ON 4-7SEGMENTS (DELAY TO VISIBILITY) */
		for (u8 i=0;i<=10;i++){
			SEVENSEG_displayNum(seg1_counter,COM1);
			_delay_ms(10);
			SEVENSEG_displayNum(seg2_counter,COM2);
			_delay_ms(10);
			SEVENSEG_displayNum(seg3_counter,COM3);
			_delay_ms(10);
			SEVENSEG_displayNum(seg4_counter,COM4);
			_delay_ms(10);
		}
		/* INCREASING 1st 7SEGMENT AND DECREASE 3rd 7-SEGMENT */
		seg1_counter++;
		seg3_counter--;
		
		if ((seg1_counter>9 && seg2_counter<=9) && (seg3_counter<0 && seg4_counter>=0)){
			seg2_counter++;
			seg4_counter--;
			seg1_counter=0;
			seg3_counter=9;
		}
		
		else if (seg2_counter>9 && seg4_counter<0 ){
			u8 seg1_counter=0;
			u8 seg2_counter=0;
			u8 seg3_counter=9;
			u8 seg4_counter=9;
		}
		
	}
	_delay_ms(40);
	
}