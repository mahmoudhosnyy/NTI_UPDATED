#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "ADC_interface.h"
#include "DIO_interface.h"

#include "LCD_interface.h"


u16 Result=0;
void fun(void){
	LCD_moveCursor(0,0);
	LCD_intgerToString(Result);
}

void main (void)
{
 GIE_enable();
ADC_init();
DIO_SetPinDirection(PORTA,PIN0,INPUT);
LCD_init();
 ADC_channelSelection(ADC0);
ADC_setCallBack(&Result,fun);
	while(1)
	{
	    ADC_startConversion();
	}
}
