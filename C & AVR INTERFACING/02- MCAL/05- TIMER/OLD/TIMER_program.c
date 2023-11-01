/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 27 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "TIMER_private.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"


void TIMER0_init(void){
#if TIMER_MODE==NORMAL_MODE
TCCR0_Reg->WGM00=0b0;
TCCR0_Reg->WGM01=0b0;
#elif TIMER_MODE==PWM_PHASE_CORRECT_MODE
TCCR0_Reg->WGM00=0b0;
TCCR0_Reg->WGM01=0b1;
TCCR0_Reg->COM=OC0_PHASE_CORRECT_PWM_MODE;
#elif TIMER_MODE==CTC_MODE
TCCR0_Reg->WGM00=0b1;
TCCR0_Reg->WGM01=0b0;
TCCR0_Reg->COM=OC0_CTC_NON_PWM_MODE;
#elif TIMER_MODE==FAST_PWM_MODE
TCCR0_Reg->WGM00=0b1;
TCCR0_Reg->WGM01=0b1;
TCCR0_Reg->COM=OC0_FAST_PWM_MODE;
#endif

#ifdef OVERFLOW_ISR_ENABLE
TIMSK_Reg->TOIE0=TIMER_OVERFLOW_INTERRUPT_ENABLE;
#endif

#ifdef COMPARE_MATCH_ISR_ENABLE
TIMSK_Reg->OCIE0=TIMER_COMPARE_MATCH_INTERRUPT_ENABLE;
#endif
}

void TIMER0_start(void){
TCCR0_Reg->CS=CLOCK_SELECTION;	
}

void TIMER0_stop(void){
TCCR0_Reg->CS=STOP_TIMER;
}

void TIMER0_setPreloadValue(u8 val){
TCNT0_Reg=val;
}

u8 TIMER0_getTimerValue(void){
	return TCNT0_Reg;
}

/* SYS FREQ = 16 MHZ , PRESCALAR =1024 >> ticktime= 64 microsec ..OVERFLOW = 256*64=16384 microsec
DESIRED COUNTS = desiredtime_ms/16384microsec */
void TIMER0_voidDelay_ms(u32 Local_u32Delay)
{
	// 16384 usec
	u32 count = (u32)((Local_u32Delay) / 16.384);
	f32 Reminder = Local_u32Delay / 16.384;
	Reminder = Reminder - count;
	u32 NoOFOV = 0;
	if(Reminder != 0.00)
	{
		NoOFOV = count +1 ;
		u8 New_Preload = 256 * (1 - Reminder);
		TIMER0_setPreloadValue(New_Preload);
	}
	TIMER0_start();
	for(u8 i = 0; i <= NoOFOV; i++)
	{
		while(TIFR_Reg->TOV0 == 0);
		TIFR_Reg->TOV0 = 1;
	}
	TIMER0_stop();
} 


void TIMER0_setPWMCompareMatchValue(u8 duty_cycle_val){
	u8 compare_value=0;
	if (duty_cycle_val<=100){
	u8 compare_value=((u32)(duty_cycle_val*255))/100;
	OCR0_Reg=compare_value;
	}
}


#ifdef OVERFLOW_ISR_ENABLE
static volatile void (*g_ptr)(void)=NULL;
void TIMER0_setCallBack(void (*a_ptr)(void)){
	if (a_ptr!=NULL){
		g_ptr=a_ptr;
	}
}

void __vector_11() __attribute__((signal));
void __vector_11(){
	if (g_ptr!=NULL){
		g_ptr();
	}
}

#endif