/*
 * UART_interface.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Mahmoud Hosny
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit(void);
void UART_voidTransmit(u8 Copy_u8Data);
u8 UART_u8Receive(void);
void UART_voidSendString(u8* Copy_pvString);
void UART_receiveString(u8* Copy_pvString);
void UART_voidSendNumber(s32 Copy_s32Number);

#endif
