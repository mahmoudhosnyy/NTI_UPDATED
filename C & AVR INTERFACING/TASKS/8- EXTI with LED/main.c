#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "util/delay.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "DIO_interface.h"


void fun(void){
	LED_on(LED_RED);
	_delay_ms(1000);
	LED_off(LED_RED);
}
void main(void){
	LED_init();
	GIE_enable();
	EXTI_enable(EXTI_1,FALLING_EDGE);
	EXTI1_callback(fun);
	while (1){

	}
	
}



