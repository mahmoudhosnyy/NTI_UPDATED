/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 23 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define EXTI_0  0
#define EXTI_1  1
#define EXTI_2  2

#define RISING_EDGE 0
#define FALLING_EDGE 1
#define ONCHANGE 2

void EXTI_enable(u8 EXTI_channel,u8 Change_state);
void EXTI_disable(u8 EXTI_channel);
void __vector_1()__attribute__((signal));
void __vector_2()__attribute__((signal));
void __vector_3()__attribute__((signal));
void EXTI0_callback(void (*a_ptr)(void));
void EXTI1_callback(void (*a_ptr)(void));
void EXTI2_callback(void (*a_ptr)(void));


#endif