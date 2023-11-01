/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 24 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "TIMER_private.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"

/************************************* TIMER0 ***********************************************/
void TIMER0_VoidInit(void)
{
#if TIMER0_MODE == Normal_MODE
	TCCR0_Reg->WGM01 = 0;
	TCCR0_Reg->WGM00 = 0;
	TIMSK_Reg->TOIE0 = 1;

#elif TIMER0_MODE == PWM__PHASE_CORRECT_MODE
	TCCR0_Reg->WGM01 = 0;
	TCCR0_Reg->WGM00 = 1;
#elif TIMER0_MODE == CTC_MODE
	TCCR0_Reg->WGM01 = 1;
	TCCR0_Reg->WGM00 = 0;
	TIMSK_Reg->OCIE0 = 1;
#elif TIMER0_MODE == FAST_PWM_MODE
	DIO_SetPinDirection(PORTB, PIN3, OUTPUT);
	TCCR0_Reg->WGM01 = 1;
	TCCR0_Reg->WGM00 = 1;
	TCCR0_Reg->COM0 = TIMER0_OC0_MODE;

#else
	//return Error

#endif
	TCCR0_Reg->CS0 = TIMER0_PRESCALAR;
}
void TIMER0_VoidStop(void)
{
	TCCR0_Reg->CS0 = TIMER_0_NO_CLOCK;
}
void TIMER0_VoidStart(void)
{
	TCCR0_Reg->CS0 = TIMER0_PRESCALAR;
}
void TIMER0_VoidSetPreload(u8 copy_u8PRELOAD)
{
	TCNT0_Reg = copy_u8PRELOAD;
}
u8 TIMER0_VoidVal(void)
{
	return TCNT0_Reg;
}

void TIMER0_voidDelay_ms(u32 Local_u32Delay)
{
	// 16384 usec
	u32 Count = (u32)((Local_u32Delay) / 16.384);
	f32 Reminder = Local_u32Delay / 16.384;
	Reminder = Reminder - Count;
	u32 NoOFOV = 0;
	if(Reminder != 0.00)
	{
		NoOFOV = Count +1 ;
		u8 New_Preload = 256 * (1 - Reminder);
		TIMER0_VoidSetPreload(New_Preload);
	}
	TIMER0_VoidStart();
	for(u8 i = 0; i <= NoOFOV; i++)
	{
		while(TIFR_Reg->TOV0 == 0);
		TIFR_Reg->TOV0 = 1;
	}
}
static void (*TIMER0_CallBackPTR_Normal)(void);

void TIMER_voidSetCallBack(void (*ptr_timer)(void))
{
	if(ptr_timer != NULL)
	{
		TIMER0_CallBackPTR_Normal = ptr_timer;
	}
	else
	{
		//Return Error
	}
}

//NORMAL_MODE
void __vector_11(void)		__attribute__((signal));
void __vector_11(void)
{
	if(TIMER0_CallBackPTR_Normal != NULL)
	{
		TIMER0_CallBackPTR_Normal();
	}
	else
	{
		//No Code
	}
}
/*	PWM Functions	*/
void TIMER0_VoidSetPWMCompareMatch(u8 copy_u8Val )
{
	u8 Torq =0 ;

	Torq = (u8)((u32)(255 * copy_u8Val) / 100);
	OCR0_Reg = Torq;
}




/************************************* TIMER1 ***********************************************/

void TIMER1_voidInit(void)
{
#if TIMER1_MODE == TIMER1_NORMAL_MODE
	TCCR1A_Reg->WGM101 = (TIMER1_NORMAL_MODE & 0b0011);
	TCCR1B_Reg->WGM123 = (TIMER1_NORMAL_MODE & 0b1100);
#elif TIMER1_MODE == TIMER1_PWM_PHASECORRECT_8BIT
	TCCR1A_Reg->WGM101 = (TIMER1_PWM_PHASECORRECT_8BIT & 0b0011);
	TCCR1B_Reg->WGM123 = (TIMER1_PWM_PHASECORRECT_8BIT & 0b1100);
#elif TIMER1_MODE == TIMER1_PWM_PHASECORRECT_9BIT
	TCCR1A_Reg->WGM101 = (TIMER1_PWM_PHASECORRECT_9BIT & 0b0011);
	TCCR1B_Reg->WGM123 = (TIMER1_PWM_PHASECORRECT_9BIT & 0b1100);
#elif TIMER1_MODE == TIMER1_PWM_PHASECORRECT_10BIT
	TCCR1A_Reg->WGM101 = (TIMER1_PWM_PHASECORRECT_10BIT & 0b0011);
	TCCR1B_Reg->WGM123 = (TIMER1_PWM_PHASECORRECT_10BIT & 0b1100);
#elif TIMER1_MODE == TIMER1_CTC_MODE
	TCCR1A_Reg->WGM101 = (TIMER1_CTC_MODE & 0b0011);
	TCCR1B_Reg->WGM123 = (TIMER1_CTC_MODE & 0b1100);
#elif TIMER1_MODE == TIMER1_FAST_PWM_8BIT
	TCCR1A_Reg->WGM101 = (TIMER1_FAST_PWM_8BIT & 0b0011);
	TCCR1B_Reg->WGM123 = (TIMER1_FAST_PWM_8BIT & 0b1100);
#elif TIMER1_MODE == TIMER1_FAST_PWM_9BIT
	TCCR1A_Reg->WGM101 = (TIMER1_FAST_PWM_9BIT & 0b0011);
	TCCR1B_Reg->WGM123 = (TIMER1_FAST_PWM_9BIT & 0b1100);
#elif TIMER1_MODE == TIMER1_FAST_PWM
	DIO_SetPinDirection(PORTD, PIN5, OUTPUT);
	TCCR1A_Reg->WGM101 = (TIMER1_FAST_PWM & 0b0011);
	TCCR1B_Reg->WGM123 = (TIMER1_FAST_PWM & 0b1100);
	TCNT1_Reg = 0;

#endif

	TCCR1B_Reg->CS = TIMER1_PRESCALAR;
}
void TIMER1_voidOCRA1Mode(OC1A_MODE_TYPE OC1A_Mode)
{
	switch (OC1A_Mode)
	{
	case OCRA_DISCONNECTED:
		TCCR1A_Reg->COM1A = OCRA_DISCONNECTED;
		break;
	case OCRA_TOGGLE:
		TCCR1A_Reg->COM1A = OCRA_TOGGLE;
		break;
	case OCRA_NON_INVERTING:
		TCCR1A_Reg->COM1A = OCRA_NON_INVERTING;
		break;
	case OCRA_INVERTING:
		TCCR1A_Reg->COM1A = OCRA_INVERTING;
		break;
	default:
		//No Code
		break;
	}
}
void TIMER1_voidOCRB1Mode(OC1B_MODE_TYPE OC1B_Mode)
{
	switch (OC1B_Mode)
	{
	case OCRB_DISCONNECTED:
		TCCR1A_Reg->COM1B = OCRB_DISCONNECTED;
		break;
	case OCRB_TOGGLE:
		TCCR1A_Reg->COM1B = OCRB_TOGGLE;
		break;
	case OCRB_NON_INVERTING:
		TCCR1A_Reg->COM1B = OCRB_NON_INVERTING;
		break;
	case OCRB_INVERTING:
		TCCR1A_Reg->COM1B = OCRB_INVERTING;
		break;
	default:
		//No Code
		break;
	}
}
void TIMER1_OVF_InterruptEnable(void)
{
	TIMSK_Reg->TOIE1 = 1;
}
void TIMER1_OVF_InterruptDisable(void)
{
	TIMSK_Reg->TOIE1 = 0;
}

void TIMER1_OCA_InterruptEnable(void)
{
	TIMSK_Reg->OCIE1A = 1;
}
void TIMER1_OCA_InterruptDisable(void)
{
	TIMSK_Reg->OCIE1A = 0;
}

void TIMER1_OCB_InterruptEnable(void)
{
	TIMSK_Reg->OCIE1B = 1;
}
void TIMER1_OCB_InterruptDisable(void)
{
	TIMSK_Reg->OCIE1B = 0;
}

void TIMER1_voidSetOVFValue(u16 Local_OVFvalue)
{
	ICR1_Reg = Local_OVFvalue;
}
void TIMER1_voidSetOCRAValue(u16 Local_OCRAvalue)
{
	OCR1A_Reg = Local_OCRAvalue;
}
void TIMER1_voidSetOCRBValue(u16 Local_OCRBvalue)
{
	OCR1B_Reg = Local_OCRBvalue;
}
static void (*TIMER1_GPTF_OVF) (void) = NULL;
static void (*TIMER1_GPTF_OCA) (void) = NULL;
static void (*TIMER1_GPTF_OCB) (void) = NULL;

void TIMER1_voidSetCallBackOVF(void(*Local_PTF)(void))
{
	if(Local_PTF != NULL)
	{
		TIMER1_GPTF_OVF = Local_PTF;
	}
	else
	{
		// Return Null error
	}
}
void TIMER1_voidSetCallBackOCA(void(*Local_PTF)(void))
{
	if(Local_PTF != NULL)
	{
		TIMER1_GPTF_OCA = Local_PTF;
	}
	else
	{
		// Return Null error
	}
}
void TIMER1_voidSetCallBackOCB(void(*Local_PTF)(void))
{
	if(Local_PTF != NULL)
	{
		TIMER1_GPTF_OCB = Local_PTF;
	}
	else
	{
		// Return Null error
	}
}


//OVF
void __vector_9(void)		__attribute__((signal));
void __vector_9(void)
{
	if(TIMER1_GPTF_OVF != NULL)
	{
		TIMER1_GPTF_OVF();
	}
	else
	{
		// Return Null error
	}
}
//COMPB
void __vector_8(void)		__attribute__((signal));
void __vector_8(void)
{
	if(TIMER1_GPTF_OCB != NULL)
	{
		TIMER1_GPTF_OCB();
	}
	else
	{
		// Return Null error
	}
}
//COMPA
void __vector_7(void)		__attribute__((signal));
void __vector_7(void)
{
	if(TIMER1_GPTF_OCA != NULL)
	{
		TIMER1_GPTF_OCA();
	}
	else
	{
		// Return Null error
	}
}
