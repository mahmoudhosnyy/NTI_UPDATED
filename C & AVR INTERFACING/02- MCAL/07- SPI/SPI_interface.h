/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 30 Oct 2023				*/
/* Version : V01                        */
/****************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_initMaster(void);
void SPI_initSlave(void);
u8 SPI_sendReceiveByte(u8 data);
void SPI_sendString(const u8 *str);
void SPI_receiveString(u8 *str);

void SPI_setCallBack(void(*a_ptr)(void));


#endif