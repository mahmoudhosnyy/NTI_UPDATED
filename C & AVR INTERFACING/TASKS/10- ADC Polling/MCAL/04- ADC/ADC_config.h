/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 24 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*******************************************/
/** PRESCALAR OPTIONS : 
1-DIV_FACTOR_2
2-DIV_FACTOR_4
3-DIV_FACTOR_8
4-DIV_FACTOR_16
5-DIV_FACTOR_32
6-DIV_FACTOR_64
7-DIV_FACTOR_128 
**/
#define PRESCALAR DIV_FACTOR_128
/********************************************/

/** VOLTAGE REFERENCE OPTIONS :
1-AREF
2-AVCC
3-INTERNAL
**/
#define VOLTAGE_REFERENCE AVCC

/********************************************/

/** FOR TRIGGER ENABLE : DEFINE TRIGGER_ENABLE **/
/** TRIGGER MODE OPTIONS :
1-FREE_RUNNING_MODE
2-ANALOG_COMPARATOR_MODE
3-EXTERNAL_INTERRUPT_MODE
4-TIMER0_COMPARE_MATCH_MODE
5-TIMER0_OVERFLOW_MODE
6-TIMER_COMPARE_MATCH_B_MODE
7-TIMER1_OVERFLOW_MODE
8-TIMER1_CAPTURE_EVENT
**/

#define TRIGGER_DISABLE

#ifdef TRIGGER_ENABLE
#define TRIGGER_SOURCE			EXTERNAL_INTERRUPT_MODE
#endif

/*******************************************/
#define TIME_OUT				100000UL
/*******************************************/

/** INTERRUPT OPTIONS :
1-ISR_ENABLE
2-ISR_Polling
**/
#define ISR_Polling

/**********************************************/

/** DATA ORIGINIZATION OPTIONS :
1-ADJUST RIGHT
2-ADJUST LEFT
**/
#define DATA_ORGINIZATION ADJUST_RIGHT

#endif