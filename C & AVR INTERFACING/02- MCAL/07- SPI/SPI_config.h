/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 30 Oct 2023				*/
/* Version : V01                        */
/****************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define SPI_MOSI_PORT    PORTB
#define SPI_MOSI_PIN	 PIN5

#define SPI_MISO_PORT    PORTB
#define SPI_MISO_PIN     PIN6

#define SPI_SS_PORT      PORTB
#define SPI_SS_PIN       PIN4

#define SPI_SCK_PORT     PORTB
#define SPI_SCK_PIN      PIN7


/*** ISR OPTIONS:
1- SPI_ISR_ENABLE
2- SPI_ISR_DISABLE
**/
#define SPI_ISR_DISABLE

/** DORD OPTIONS :
1- DORD_LSB_TRANSMIT_FIRST
2- DORD_MSB_TRANSMIT_FIRST
**/
#define DORD_SELECT  DORD_MSB_TRANSMIT_FIRST

/** CLOCK OPTIONS :
1- PRESCALAR_4
2- PRESCALAR_16
3- PRESCALAR_64
3- PRESCALAR_128
4- DOUBLE_SPEED_PRESCALAR_2
5- DOUBLE_SPEED_PRESCALAR_8
6- DOUBLE_SPEED_PRESCALAR_32
7- DOUBLE_SPEED_PRESCALAR_64
**/
#define PRESCALAR PRESCALAR_4

/** CLOCK PHASE OPTIONS :
1- LEADING_SAMPLE_TRAILING_SETUP
2- LEADING_SETUP_TRAILING_SAMPLE
**/
#define CLOCK_PHASE LEADING_SAMPLE_TRAILING_SETUP

/** CLOCK POLARITY OPTIONS :
1- LEADING_RISING_TRAILING_FALLING_POLARITY
2- LEADING_FALLING_TRAILING_RISING_POLARITY
**/
#define CLOCK_POLARITY LEADING_RISING_TRAILING_FALLING_POLARITY


#endif