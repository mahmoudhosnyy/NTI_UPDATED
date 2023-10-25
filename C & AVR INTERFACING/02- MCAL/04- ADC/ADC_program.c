/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 24 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"

void ADC_init(void){
	ADMUX_Reg->ADLAR=DATA_ORGINIZATION;
	ADMUX_Reg->REFS=VOLTAGE_REFERENCE;
	ADCSRA_Reg->ADPS=PRESCALAR;
	ADCSRA_Reg->ADEN=ADC_ENABLE;
#ifdef ISR_ENABLE
	ADCSRA_Reg->ADIE=ADC_INTERRUPT_ENABLE;
#endif

#ifdef TRIGGER_ENABLE
	ADCSRA_Reg->ADATE=ADC_ENABLE_TRIGGER;
	SFIOR_Reg->ADTS=TRIGGER_SOURCE;
#endif
}

ADC_ERROR_RETURN ADC_channelSelection(CHANNEL_SELECTION channel){
	ADC_ERROR_RETURN error= OK;
	if (channel <= ADC_GND){
		ADMUX_Reg->MUX=channel;
	}
	else {
		error= NUM_OUT_OF_RANGE;
	}
		return error;
}

ADC_ERROR_RETURN ADC_value(u16 *DataPointer){
	ADC_ERROR_RETURN error =OK;
	u32 counter=0;
	if (DataPointer!=NULL){
		ADCSRA_Reg->ADSC=ADC_START_CONVERSION;
		while(ADCSRA_Reg->ADIF==0 && counter<=TIME_OUT ){ counter++;}
			if (ADCSRA_Reg->ADIF==1){
				ADCSRA_Reg->ADIF=ADC_INTERRUPT_FLAG_CLEAR;
				#if DATA_ORGINIZATION == ADJUST_RIGHT
				(*DataPointer) = ADC_DATA_Reg;
				#elif DATA_ORGINIZATION == ADJUST_LEFT
				(*DataPointer) = ((u16)ADC_DATA_Reg >> 6);
				#endif
				}
			else {
				error= TIME_OUT_ERROR;
			}
	}
	else {
		error= NULL_ERROR;
	}
return error;
}

u16 ADC_mapping(u16 adc_lower_range,u16 adc_upper_range,u16 new_lower_range,u16 new_upper_range){
	u16 ADC_OLD_VALUE = 0;
				#if DATA_ORGINIZATION == ADJUST_RIGHT
				ADC_OLD_VALUE = ADC_DATA_Reg;
				#elif DATA_ORGINIZATION == ADJUST_LEFT
				ADC_OLD_VALUE = ((u16)ADC_DATA_Reg >> 6);
				#endif
u16 ADC_NEW_VALUE = (((u32)((ADC_DATA_Reg-adc_lower_range)*(new_upper_range-new_lower_range)))/(adc_upper_range-adc_lower_range))+new_lower_range;
	return ADC_NEW_VALUE;
}


#ifdef ISR_ENABLE
static volatile void (*g_ptr)(void)=NULL;
static volatile u16 *result=NULL;

/* pointer to fucntion argument : function to be executed when ADC finishes Conversion
 , result_ptr argument : to get result of conversion from ADC */
ADC_ERROR_RETURN ADC_setCallBack(u16*result_ptr,void(*a_ptr)(void)){
	ADC_ERROR_RETURN error=OK;
	
	if (result_ptr!=NULL){
		result=result_ptr;
	}
	else {
		error=NULL_ERROR;
	}
	
	if (a_ptr!=NULL){
	g_ptr=a_ptr;
	}
	else {
		error=NULL_ERROR;
	}
	return error;
}

void __vector_16(void)  _attribute__((signal));
void __vector_16(void) {
	#if DATA_ORGINIZATION == ADJUST_RIGHT
	*result = ADC_DATA_Reg;
	#elif DATA_ORGINIZATION == ADJUST_LEFT
	*result = ((u16)ADC_DATA_Reg >> 6);
	#endif
	if (g_ptr!=NULL){
		g_ptr();
	}
	else {
		// nothing
	}
}
#endif


