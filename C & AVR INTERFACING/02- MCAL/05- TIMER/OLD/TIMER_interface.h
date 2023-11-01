/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 27 Oct 2023				*/
/* Version : V01                        */
/****************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

void TIMER0_init(void);
void TIMER0_start(void);
void TIMER0_stop(void);
void TIMER0_setPreloadValue(u8 val);
u8 TIMER0_getTimerValue(void);
void TIMER0_setPWMCompareMatchValue(u8 duty_cycle_val);
void TIMER0_voidDelay_ms(u32 Local_u32Delay);
void TIMER0_setCallBack(void (*a_ptr)(void));

#endif