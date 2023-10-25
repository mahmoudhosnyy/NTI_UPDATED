/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 23 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/* REGISTERS DEFINITION */
#define MCUCR_Reg       *((volatile u8*)0x55)
#define MCUSR_Reg       *((volatile u8*)0x54)
#define GICR_Reg		*((volatile u8*)0x5B)
#define GIFR_Reg		*((volatile u8*)0x5A)

/* BITS OF MCUCR_Reg */
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

/* BITS OF MCUSR_Reg */
#define ISC2  6

/* BITS OF GICR_Reg */
#define INT2 5
#define INT0 6
#define INT1 7

/* BITS OF GIFR_Reg */
#define INTF2 5
#define INTF0 6
#define INTF1 7

#endif