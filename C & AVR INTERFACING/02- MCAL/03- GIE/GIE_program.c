/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 23 Oct 2023				*/
/* Version : V01                        */
/****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"

void GIE_enable(void){
	SET_BIT(SREG_Reg,7);
}


void GIE_disable(void){
	CLEAR_BIT(SREG_Reg,7);
}