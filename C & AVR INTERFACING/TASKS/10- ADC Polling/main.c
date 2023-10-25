#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "DIO_interface.h"

#include "LCD_interface.h"

void main (void)
{

 ADC_init();
DIO_SetPinDirection(PORTA,PIN0,INPUT);
LCD_init();
u16 Result;
ADC_channelSelection(ADC0);
	while(1)
	{
		ADC_value(&Result);
		LCD_moveCursor(0,0);
		LCD_intgerToString(Result);
	}
}