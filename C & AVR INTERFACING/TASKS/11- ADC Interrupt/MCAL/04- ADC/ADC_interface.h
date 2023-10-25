/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 24 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum {
	ADC0=0b00000,
	ADC1=0b00001,
	ADC2=0b00010,
	ADC3=0b00011,
	ADC4=0b00100,
	ADC5=0b00101,
	ADC6=0b00110,
	ADC7=0b00111,
	ADC0_ADC0_10x=0b01000,
	ADC1_ADC0_10x=0b01001,
	ADC0_ADC0_200x=0b01010,
	ADC1_ADC0_200x=0b01011,
	ADC2_ADC2_10x=0b01100,
	ADC3_ADC2_10x=0b01101,
	ADC2_ADC2_200x=0b01110,
	ADC3_ADC2_200x=0b01111,
	ADC0_ADC0_1x=0b10000,
	ADC1_ADC1_1x=0b10001,
	ADC2_ADC1_1x=0b10010,
	ADC3_ADC1_1x=0b10011,
	ADC4_ADC1_1x=0b10100,
	ADC5_ADC1_1x=0b10101,
	ADC6_ADC1_1x=0b10110,
	ADC7_ADC1_1x=0b10111,
	ADC0_ADC2_1x=0b11000,
	ADC1_ADC2_1x=0b11001,
	ADC2_ADC2_1x=0b11010,
	ADC3_ADC2_1x=0b11011,
	ADC4_ADC2_1x=0b11100,
	ADC5_ADC2_1x=0b11101,
	ADC_VBG=0b11110,
	ADC_GND=0b11111
}CHANNEL_SELECTION;


typedef enum
{
	NULL_ERROR      ,
	TIME_OUT_ERROR  ,
	OK              ,
	NUM_OUT_OF_RANGE

}ADC_ERROR_RETURN;


void ADC_init(void);
ADC_ERROR_RETURN ADC_channelSelection(CHANNEL_SELECTION channel);
ADC_ERROR_RETURN ADC_value(u16 *DataPointer);
u16 ADC_mapping(u16 adc_lower_range,u16 adc_upper_range,u16 new_lower_range,u16 new_upper_range);
ADC_ERROR_RETURN ADC_setCallBack(u16*result_ptr,void(*a_ptr)(void));

#endif