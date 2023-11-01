/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 31 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/** CLOCK OPTIONS:
1- HSI
2- HSE
3- PLL
4- HSE_BYPASS
**/
#define CLOCK_SELECTION HSI

#if CLOCK_SELECTION==PLL
	/** MULTIPLICATION FACTOR OPTIONS:
	1-  PLL_x2
	2-  PLL_x3
	3-  PLL_x4
	4-  PLL_x5
	5-  PLL_x6
	6-  PLL_x7
	7-  PLL_x8
	8-  PLL_x9
	9-  PLL_x10
	10- PLL_x11
	11- PLL_x12
	12- PLL_x13
	13- PLL_x14
	14- PLL_x15
	15- PLL_x16
	16- PLL_x16_2
	**/
	#define MULTIPLICATION_FACTOR PLL_x2
	
	/** PLL CLOCK SOURCE OPTIONS:
	1- PLL_HSI_DIVIDED_BY_2
	2- PLL_HSE
	3- PLL_HSE_DIVIDED_BY_2
	**/
	#define PLL_CLOCK_SOURCE  PLL_HSI_DIVIDED_BY_2
#endif 


/** CLOCK SECURITY SYSTEM OPTIONS :
1- ENABLE_CLOCK_SECURITY_SYSTEM
2- DISABLE_CLOCK_SECURITY_SYSTEM
**/
#define CLOCK_SECURITY_SYSTEM  DISABLE_CLOCK_SECURITY_SYSTEM



#endif 