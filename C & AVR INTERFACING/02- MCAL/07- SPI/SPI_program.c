/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 30 Oct 2023				*/
/* Version : V01                        */
/****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"



void SPI_initMaster(void){
/******** Configure SPI Master Pins *********
	 * SS(PB4)   --> Output
	 * MOSI(PB5) --> Output 
	 * MISO(PB6) --> Input
	 * SCK(PB7) --> Output
********************************************/
DIO_SetPinDirection(SPI_MOSI_PORT,SPI_MOSI_PIN,OUTPUT);
DIO_SetPinDirection(SPI_MISO_PORT,SPI_MISO_PIN,INPUT);
DIO_SetPinDirection(SPI_SS_PORT,SPI_SS_PIN,OUTPUT);
DIO_SetPinDirection(SPI_SCK_PORT,SPI_SCK_PIN,OUTPUT);

/** INTERRUPT **/
#ifdef SPI_ISR_ENABLE
SPCR_Reg->SPIE=INTERRUPT_ENABLE;
#endif

/** DATA ORDERING **/
#if DORD_SELECT==DORD_MSB_TRANSMIT_FIRST
SPCR_Reg->DORD = DORD_MSB_TRANSMIT_FIRST;
#elif DORD_SELECT==DORD_LSB_TRANSMIT_FIRST
SPCR_Reg->DORD = DORD_LSB_TRANSMIT_FIRST;
#endif

/** MASTER MODE **/
SPCR_Reg->MSTR = MASTER_MODE;

/****** CLOCK PRESCALAR *******/
#if PRESCALAR==PRESCALAR_4
SPSR_Reg->SPI2X=0b0;
SPCR_Reg->SPR1=0b0;
SPCR_Reg->SPR0=0b0;
#elif PRESCALAR==PRESCALAR_16
SPSR_Reg->SPI2X=0b0;
SPCR_Reg->SPR1=0b0;
SPCR_Reg->SPR0=0b1;
#elif PRESCALAR==PRESCALAR_64
SPSR_Reg->SPI2X=0b0;
SPCR_Reg->SPR1=0b1;
SPCR_Reg->SPR0=0b0;
#elif PRESCALAR==PRESCALAR_128
SPSR_Reg->SPI2X=0b0;
SPCR_Reg->SPR1=0b1;
SPCR_Reg->SPR0=0b1;
#elif PRESCALAR==DOUBLE_SPEED_PRESCALAR_2
SPSR_Reg->SPI2X=0b1;
SPCR_Reg->SPR1=0b0;
SPCR_Reg->SPR0=0b0;
#elif PRESCALAR==DOUBLE_SPEED_PRESCALAR_8
SPSR_Reg->SPI2X=0b1;
SPCR_Reg->SPR1=0b0;
SPCR_Reg->SPR0=0b1;
#elif PRESCALAR==DOUBLE_SPEED_PRESCALAR_32
SPSR_Reg->SPI2X=0b1;
SPCR_Reg->SPR1=0b1;
SPCR_Reg->SPR0=0b0;
#elif PRESCALAR==DOUBLE_SPEED_PRESCALAR_64
SPSR_Reg->SPI2X=0b1;
SPCR_Reg->SPR1=0b1;
SPCR_Reg->SPR0=0b1;
#endif

/***************/
/** CLOCK PHASE **/

#if CLOCK_PHASE==LEADING_SAMPLE_TRAILING_SETUP
SPCR_Reg->CPHA=LEADING_SAMPLE_TRAILING_SETUP;
#elif CLOCK_PHASE==LEADING_SETUP_TRAILING_SAMPLE
SPCR_Reg->CPHA=LEADING_SETUP_TRAILING_SAMPLE;
#endif

/***************/
/** CLOCK POLARITY **/
#if CLOCK_POLARITY==LEADING_RISING_TRAILING_FALLING_POLARITY
SPCR_Reg->CPOL=LEADING_RISING_TRAILING_FALLING_POLARITY;
#elif CLOCK_POLARITY==LEADING_FALLING_TRAILING_RISING_POLARITY
SPCR_Reg->CPOL=LEADING_FALLING_TRAILING_RISING_POLARITY;
#endif

/*****************/
/** SPI ENABLE **/
SPCR_Reg->SPE=SPI_ENABLE;	
}



void SPI_initSlave(void){
/******** Configure SPI Master Pins *********
	 * SS(PB4)   --> INPUT
	 * MOSI(PB5) --> INPUT 
	 * MISO(PB6) --> OUTPUT
	 * SCK(PB7) --> INPUT
********************************************/
DIO_SetPinDirection(SPI_MOSI_PORT,SPI_MOSI_PIN,INPUT);
DIO_SetPinDirection(SPI_MISO_PORT,SPI_MISO_PIN,OUTPUT);
DIO_SetPinDirection(SPI_SS_PORT,SPI_SS_PIN,INPUT);
DIO_SetPinDirection(SPI_SCK_PORT,SPI_SCK_PIN,INPUT);

/** INTERRUPT **/
#ifdef SPI_ISR_ENABLE
SPCR_Reg->SPIE=INTERRUPT_ENABLE;
#endif

/** DATA ORDERING **/
#if DORD_SELECT==DORD_MSB_TRANSMIT_FIRST
SPCR_Reg->DORD = DORD_MSB_TRANSMIT_FIRST;
#elif DORD_SELECT==DORD_LSB_TRANSMIT_FIRST
SPCR_Reg->DORD = DORD_LSB_TRANSMIT_FIRST;
#endif

/** MASTER MODE **/
SPCR_Reg->MSTR = SLAVE_MODE;

/****** CLOCK PRESCALAR *******/
#if PRESCALAR==PRESCALAR_4
SPSR_Reg->SPI2X=0b0;
SPCR_Reg->SPR1=0b0;
SPCR_Reg->SPR0=0b0;
#elif PRESCALAR==PRESCALAR_16
SPSR_Reg->SPI2X=0b0;
SPCR_Reg->SPR1=0b0;
SPCR_Reg->SPR0=0b1;
#elif PRESCALAR==PRESCALAR_64
SPSR_Reg->SPI2X=0b0;
SPCR_Reg->SPR1=0b1;
SPCR_Reg->SPR0=0b0;
#elif PRESCALAR==PRESCALAR_128
SPSR_Reg->SPI2X=0b0;
SPCR_Reg->SPR1=0b1;
SPCR_Reg->SPR0=0b1;
#elif PRESCALAR==DOUBLE_SPEED_PRESCALAR_2
SPSR_Reg->SPI2X=0b1;
SPCR_Reg->SPR1=0b0;
SPCR_Reg->SPR0=0b0;
#elif PRESCALAR==DOUBLE_SPEED_PRESCALAR_8
SPSR_Reg->SPI2X=0b1;
SPCR_Reg->SPR1=0b0;
SPCR_Reg->SPR0=0b1;
#elif PRESCALAR==DOUBLE_SPEED_PRESCALAR_32
SPSR_Reg->SPI2X=0b1;
SPCR_Reg->SPR1=0b1;
SPCR_Reg->SPR0=0b0;
#elif PRESCALAR==DOUBLE_SPEED_PRESCALAR_64
SPSR_Reg->SPI2X=0b1;
SPCR_Reg->SPR1=0b1;
SPCR_Reg->SPR0=0b1;
#endif

/***************/
/** CLOCK PHASE **/

#if CLOCK_PHASE==LEADING_SAMPLE_TRAILING_SETUP
SPCR_Reg->CPHA=LEADING_SAMPLE_TRAILING_SETUP;
#elif CLOCK_PHASE==LEADING_SETUP_TRAILING_SAMPLE
SPCR_Reg->CPHA=LEADING_SETUP_TRAILING_SAMPLE;
#endif

/***************/
/** CLOCK POLARITY **/
#if CLOCK_POLARITY==LEADING_RISING_TRAILING_FALLING_POLARITY
SPCR_Reg->CPOL=LEADING_RISING_TRAILING_FALLING_POLARITY;
#elif CLOCK_POLARITY==LEADING_FALLING_TRAILING_RISING_POLARITY
SPCR_Reg->CPOL=LEADING_FALLING_TRAILING_RISING_POLARITY;
#endif

/*****************/
/** SPI ENABLE **/
SPCR_Reg->SPE=SPI_ENABLE;
}


u8 SPI_sendReceiveByte(u8 data){
/* Initiate the communication and send data by SPI */
	SPDR_Reg = data;
/* Wait until SPI interrupt flag SPIF = 1 (data has been sent/received correctly) */	
	while (SPSR_Reg->SPIF==0){}
	return SPDR_Reg;
}

void SPI_sendString(const u8 *str){
	u8 i = 0;
	u8 received_data = 0;
	/* Send the whole string */
	while(str[i] != '\0')
	{	/*
		 * received_data contains the received data from the other device.
		 * It is a dummy data variable as we just need to send the string to other device.
		 */
		received_data = SPI_sendReceiveByte(str[i]);
		i++;
	}
}

void SPI_receiveString(u8 *str){
	u8 i = 0;
	/* Receive the first byte */
	str[i] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
	/* Receive the whole string until the '#' */
	while(str[i] != '#')
	{
		i++;
		str[i] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
	}
	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	str[i] = '\0';
}


#ifdef SPI_ISR_ENABLE

static volatile void(*g_ptr)(void)=NULL;

void SPI_setCallBack(void(*a_ptr)(void)){
	if (a_ptr!=NULL){
	g_ptr=a_ptr;	
	}
	else {// do nothing 
	}
}


void __vector_12() __attribute__((signal));
void __vector_12() {
	if (g_ptr!=NULL){
		g_ptr();
	}
	else {
		// nothing
	}
}
#endif
