/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 27 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_private.h"
#include "UART_config.h"
#include "UART_interface.h"

void UART_voidInit(void)
{
	UCSRC Local_UCSRC;
	/*Get access to UCSRC -> UMSEL = 1*/
	Local_UCSRC.URSEL = 1;
	/*Select Operating Mood*/
	Local_UCSRC.UMSEL = UART_OPERTATING_MODE;
	/*Select Parity Mood*/
	Local_UCSRC.UPM10 = UART_PARITY_MODE;
	/*Select Stop Bits*/
	Local_UCSRC.USBS = UART_STOP_BITS;
	/*Select Character size*/
	Local_UCSRC.UCSZ10 = UART_DATA_SIZE & 0b11;
	UART_UCSRB->UCSZ2 = GET_BIT(UART_DATA_SIZE,2);
	/* Assign the Value of UCSRC */
	UART_UCSRC = *((u8*)&Local_UCSRC);
	/*Set baud rate*/
	UART_UBRRL = UART_BAUD_RATE;
	if(UART_BAUD_RATE > 255)
	{
		UART_UBRRH = (UART_BAUD_RATE >> 8);
	}
}

void UART_voidTransmit(u8 Copy_u8Data)
{
while(GET_BIT(UCSRA,UCSRA_UDRE)==0);

UDR=Copy_u8Data;
}

u8 UART_u8Receive(void)
{
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);

return UDR;
}


void UART_voidSendString(u8* Copy_pvString)
{

u8 counter=0;

while(Copy_pvString[counter]!='\0')
{
	UART_voidTransmit(Copy_pvString[counter]);
	counter++;
}

}

void UART_receiveString(u8* Copy_pvString)
{
	u8 counter = 0;
	/* Receive the first byte */
	Copy_pvString[i] = UART_u8Receive();
	/* Receive the whole string until the '#' */
	while(Copy_pvString[i] != '#')
	{
		i++;
		Copy_pvString[i] = UART_u8Receive();
	}
	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Copy_pvString[i] = '\0';
}

void UART_voidSendNumber(s32 Copy_s32Number)
{
			if(Copy_s32Number<0)
			{
				UART_voidTransmit('-');
				Copy_s32Number= -Copy_s32Number;
			}
			if(Copy_s32Number==0)
			{
				UART_voidTransmit('0');
				return;
			}
u8 NUM[10];
u8 Local_u8Counter=0;
			while(Copy_s32Number>0)
			{
				NUM[Local_u8Counter++]=(Copy_s32Number%10)+'0';
				Copy_s32Number/=10;
			}
					/*reverse*/
			for(u8 i=Local_u8Counter;i>0;i--)
			{
				UART_voidTransmit(NUM[i-1]);
			}
}




