/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 20 Oct 2023				*/
/* Version : V01                        */
/****************************************/


#ifndef SEVENSEG_INTERFACE_H
#define SEVENSEG_INTERFACE_H

#define COM1 1
#define COM2 2
#define COM3 3
#define COM4 4

void SEVENSEG_init(void);
void SEVENSEG_displayNum(u8 num,u8 com_num);



#endif