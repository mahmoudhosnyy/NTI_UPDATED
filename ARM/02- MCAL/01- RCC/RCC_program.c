/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 31 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"


void RCC_voidInit(void){
	u32 Loc_TimeOut=0;
	
	#if CLOCK_SELECTION==HSI
	/** 1- CHOOSE CLOCK SOURCE > HSI 
		2- ENABLE HSI 
		3- POLLING ON HSI FLAG (WAITING CLOCK SOURCE TO BE STABLE)
	**/
	RCC_CFGR_REG->SWS=0b00;
	RCC_CR_REG->HSION=0b1;
	while( (RCC_CR_REG->HSIRDY==0b0) && Loc_TimeOut<100000){Loc_TimeOut++;}
	if (Loc_TimeOut>=100000){/*Return TimeOut Error*/}
	
	#elif CLOCK_SELECTION==HSE
	/** 1- CHOOSE CLOCK SOURCE > HSE 
		2- ENABLE HSE 
		3- POLLING ON HSE FLAG (WAITING CLOCK SOURCE TO BE STABLE)
	**/
	RCC_CFGR_REG->SWS=0b01;
	RCC_CR_REG->HSEON=0b1;
	while( (RCC_CR_REG->HSERDY==0b0) && Loc_TimeOut<100000){Loc_TimeOut++;}
	if (Loc_TimeOut>=100000){/*Return TimeOut Error*/}
	
	#elif CLOCK_SELECTION==PLL
	/** 1- CHOOSE CLOCK SOURCE > PLL 
		2- CHOOSE MULTIPLICATION FACTOR 
		3- CHOOSE PLL SOURCE > HSI/2 OR HSE OR HSE/2 (FIRST ENABLE CLOCK SOURCE YOU CHOOSE FOR PLL)
		4- ENABLE PLL CLOCK
		5- POLLING ON PLL FLAG
	**/
	RCC_CFGR_REG->SWS=0b10;
		#if (MULTIPLICATION_FACTOR>=PLL_x16_2 || MULTIPLICATION_FACTOR<=PLL_x2)
			RCC_CFGR_REG->PLLMUL=MULTIPLICATION_FACTOR;
		#else 
			#warning "Wrong Multiplication Factor"
		#endif /** PLL MULTIPLICATION FACTOR SELECTION **/
		
		#if   PLL_CLOCK_SOURCE==PLL_HSI_DIVIDED_BY_2
			RCC_CR_REG->HSION=0b1;
			RCC_CFGR_REG->PLLSRC=0b0;
		#elif PLL_CLOCK_SOURCE==PLL_HSE
			RCC_CR_REG->HSEON=0b1;
			RCC_CFGR_REG->PLLSRC=0b1;
			RCC_CFGR_REG->XTPRE=0b0;
		#elif PLL_SOURCE==PLL_HSE_DIVIDED_BY_2
			RCC_CR_REG->HSEON=0b1;
			RCC_CFGR_REG->PLLSRC=0b1;
			RCC_CFGR_REG->XTPRE=0b1;
		#endif /** PLL CLOCK SOURCE SELECTION **/
		
	RCC_CR_REG->PLLON=0b1;
	while( (RCC_CR_REG->PLLRDY==0b0) && Loc_TimeOut<100000){Loc_TimeOut++;}
	if (Loc_TimeOut>=100000){/*Return TimeOut Error*/}
	
	#elif CLOCK_SELECTION==HSE_BYPASS
	/** 1- DISABLE HSE
		2- ENABLE HSE BYPASS (WHILE ENABLLINGHSE BYPASS, HSEON SHOULD BE DISABLE )
		3- CHOOSE CLOCK SOURCE > HSE
		4- ENABLE HSE
		5- POLLING ON HSE FLAG (WAITING CLOCK SOURCE TO BE STABLE)
	**/
	RCC_CR_REG->HSEON=0b0;
	RCC_CR_REG->HSEPYB=0b1;
	RCC_CFGR_REG->SWS=0b01;
	RCC_CR_REG->HSEON=0b1;
	while( (RCC_CR_REG->HSERDY==0b0) && Loc_TimeOut<100000){Loc_TimeOut++;}
	if (Loc_TimeOut>=100000){/*Return TimeOut Error*/}	
	
	#else 
		#error "Wrong Clock Source Configuration"
	#endif /** end of clock selection **/
	
	
	
	#if CLOCK_SECURITY_SYSTEM==ENABLE_CLOCK_SECURITY_SYSTEM
		RCC_CR_REG->CSSON=0b1;
	#elif CLOCK_SECURITY_SYSTEM==DISABLE_CLOCK_SECURITY_SYSTEM
		RCC_CR_REG->CSSON=0b0;
	#else
		#warning "Wrong Clock Security System Configuration"
	#endif
}


void RCC_voidEnablePeripheral(u8 Copy_u8PeripheralBus,u8 Copy_u8Peripheral){
		switch( Copy_u8PeripheralBus ){
			case AHB_BUS  : SET_BIT(RCC_AHBENR_REG,Copy_u8Peripheral); break;
			case APB1_BUS : SET_BIT(RCC_APB1ENR_REG,Copy_u8Peripheral); break;
			case APB2_BUS : SET_BIT(RCC_APB2ENR_REG,Copy_u8Peripheral); break;
		}
}

void RCC_voidDisablePeripheral(u8 Copy_u8PeripheralBus,u8 Copy_u8Peripheral){
		switch( Copy_u8PeripheralBus ){
			case AHB_BUS  : CLEAR_BIT(AHBENR_REG,Copy_u8Peripheral); break;
			case APB1_BUS : CLEAR_BIT(APB1ENR_REG,Copy_u8Peripheral); break;
			case APB2_BUS : CLEAR_BIT(APB2ENR_REG,Copy_u8Peripheral); break;
		}
}

void RCC_voidResetPeripheral(u8 Copy_u8PeripheralBus,u8 Copy_u8Peripheral){
		switch( Copy_u8PeripheralBus ){
			case APB1_BUS : SET_BIT(RCC_APB1RSTR_REG,Copy_u8Peripheral); break;
			case APB2_BUS : SET_BIT(RCC_APB2RSTR_REG,Copy_u8Peripheral); break;
		}
}