/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 23 Oct 2023				*/
/* Version : V01                        */
/****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"



static void (*g_ptr[3])(void)={NULL};

void EXTI_enable(u8 EXTI_channel,u8 Change_state){
	
	if (EXTI_channel==EXTI_0){
		if (Change_state== RISING_EDGE){
			SET_BIT(MCUCR_Reg,ISC00);
			SET_BIT(MCUCR_Reg,ISC01);
		}
		else if (Change_state== FALLING_EDGE){
			CLEAR_BIT(MCUCR_Reg,ISC00);
			SET_BIT(MCUCR_Reg,ISC01);			
		}
		
		else if (Change_state== ONCHANGE){
			SET_BIT(MCUCR_Reg,ISC00);
			CLEAR_BIT(MCUCR_Reg,ISC01);					
		}
		else {/* DO NOTHING */}
		
		/* ENABLE EXTI */
		SET_BIT(GICR_Reg,INT0);	
	}
	
	
	else if (EXTI_channel==EXTI_1){
		
		if (Change_state== RISING_EDGE){
			SET_BIT(MCUCR_Reg,ISC10);
			SET_BIT(MCUCR_Reg,ISC11);
		}
		else if (Change_state== FALLING_EDGE){
			CLEAR_BIT(MCUCR_Reg,ISC10);
			SET_BIT(MCUCR_Reg,ISC11);			
		}
		
		else if (Change_state== ONCHANGE){
			SET_BIT(MCUCR_Reg,ISC10);
			CLEAR_BIT(MCUCR_Reg,ISC11);					
		}
		else {/* DO NOTHING */}
		
		/* ENABLE EXTI */
		SET_BIT(GICR_Reg,INT1);
	}
	
	else if (EXTI_channel==EXTI_2){
		
		if (Change_state== RISING_EDGE){
			SET_BIT(MCUSR_Reg,ISC2);
		}
		else if (Change_state== FALLING_EDGE){
			CLEAR_BIT(MCUSR_Reg,ISC2);			
		}

		else {/* DO NOTHING */}
		
		/* ENABLE EXTI */
		SET_BIT(GICR_Reg,INT2);
	}
	
	else {/* do nothing */}
}




void EXTI_disable(u8 EXTI_channel){
	if (EXTI_channel==EXTI_0){
         CLEAR_BIT(GICR_Reg,INT0);
	}
	else if (EXTI_channel==EXTI_1){
		 CLEAR_BIT(GICR_Reg,INT1);
	}
	else if (EXTI_channel==EXTI_2){
	     CLEAR_BIT(GICR_Reg,INT2);		
	}
	
	else {/* do nothing */}
} 


void EXTI0_callback(void (*a_ptr)(void)){
	if (a_ptr!=NULL)
	{
		g_ptr[0]=a_ptr;
	}
}
void EXTI1_callback(void (*a_ptr)(void)){
	if (a_ptr!=NULL)
	{	
		g_ptr[1]=a_ptr;
	}
}
void EXTI2_callback(void (*a_ptr)(void)){
	if (a_ptr!=NULL)
	{
		g_ptr[2]=a_ptr;
	}
}

void __vector_1(){
	if (g_ptr[0]!=NULL){
		g_ptr[0]();
	}
}

void __vector_2(){
	if (g_ptr[1]!=NULL){
		g_ptr[1]();
	}
}

void __vector_3(){
	if (g_ptr[2]!=NULL){
		g_ptr[2]();
	}	
}
