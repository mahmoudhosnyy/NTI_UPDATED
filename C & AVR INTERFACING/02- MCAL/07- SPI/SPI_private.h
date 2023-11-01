/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 30 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/****************************************************************/
typedef struct {
	u8 SPR0:1;
	u8 SPR1:1;
	u8 CPHA:1;
	u8 CPOL:1;
	u8 MSTR:1;
	u8 DORD:1;
	u8 SPE:1;
	u8 SPIE:1;	
}SPCR;

#define INTERRUPT_ENABLE 0b1
#define SPI_ENABLE 0b1
#define DORD_LSB_TRANSMIT_FIRST 0b1
#define DORD_MSB_TRANSMIT_FIRST 0b0
#define MASTER_MODE 0b1
#define SLAVE_MODE 0b0
#define LEADING_RISING_TRAILING_FALLING_POLARITY 0b0
#define LEADING_FALLING_TRAILING_RISING_POLARITY 0b1
#define LEADING_SAMPLE_TRAILING_SETUP 0b0
#define LEADING_SETUP_TRAILING_SAMPLE 0b1

#define SPCR_Reg          ((volatile SPCR*)0x2D)
/****************************************************************/
typedef struct {
	u8 SPI2X:1;
	u8  :5;
	u8 WCOL:1;
	u8 SPIF:1;	
}SPSR;


#define SPSR_Reg         ((volatile SPSR*)0x2E)             
/****************************************************************/
#define SPDR_Reg         *((volatile u8*)0x2F)

/****************************************************************/
/** PRESCALAR **/
#define PRESCALAR_4               1
#define PRESCALAR_16  			  2
#define PRESCALAR_64  			  3
#define PRESCALAR_128             4
#define DOUBLE_SPEED_PRESCALAR_2  5
#define DOUBLE_SPEED_PRESCALAR_8  6
#define DOUBLE_SPEED_PRESCALAR_32 7
#define DOUBLE_SPEED_PRESCALAR_64 8
/*****************************************************************/
/*
 * Default SPI data value used in case we need to receive a byte from the other device,
 * without need to send a data to it
 */
#define SPI_DEFAULT_DATA_VALUE 0xFF



#endif