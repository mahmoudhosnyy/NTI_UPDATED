/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 20 Oct 2023				*/
/* Version : V01                        */
/****************************************/


#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#define LED_RED    0
#define LED_GREEN  1
#define LED_BLUE   2
#define LED_YELLOW 3 

#define LED_RED_PORT      PORTB 
#define LED_RED_PIN       PIN7 
   
#define LED_GREEN_PORT    PORTA
#define LED_GREEN_PIN     PIN4 
 
#define LED_BLUE_PORT 	  PORTA
#define LED_BLUE_PIN      PIN5

#define LED_YELLOW_PORT   PORTA
#define LED_YELLOW_PIN    PIN6


void LED_init (void);
void LED_on(u8 led_colour);
void LED_off(u8 led_colour);
void LED_ALL_ON(void);
void LED_ALL_OFF(void);
void LED_binary(u8 num);


#endif