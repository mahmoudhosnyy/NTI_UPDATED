/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 22 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define	KEYPAD_NUM_COLS 4
#define	KEYPAD_NUM_ROWS 4

/* Keypad Port and PIN Configurations */
#define KEYPAD_FIRST_ROW_PORT_ID          PORTC
#define KEYPAD_FIRST_ROW_PIN_ID           PIN5
#define KEYPAD_SECOND_ROW_PORT_ID         PORTC
#define KEYPAD_SECOND_ROW_PIN_ID          PIN4
#define KEYPAD_THIRD_ROW_PORT_ID          PORTC
#define KEYPAD_THIRD_ROW_PIN_ID           PIN3
#define KEYPAD_FOURTH_ROW_PORT_ID         PORTC
#define KEYPAD_FOURTH_ROW_PIN_ID          PIN2

#define ROW_PORT_DATA     {KEYPAD_FIRST_ROW_PORT_ID,KEYPAD_SECOND_ROW_PORT_ID,KEYPAD_THIRD_ROW_PORT_ID,KEYPAD_FOURTH_ROW_PORT_ID}
#define ROW_PIN_DATA      {KEYPAD_FIRST_ROW_PIN_ID,KEYPAD_SECOND_ROW_PIN_ID,KEYPAD_THIRD_ROW_PIN_ID,KEYPAD_FOURTH_ROW_PIN_ID}

#define KEYPAD_FIRST_COL_PORT_ID          PORTD
#define KEYPAD_FIRST_COL_PIN_ID           PIN7
#define KEYPAD_SECOND_COL_PORT_ID         PORTD
#define KEYPAD_SECOND_COL_PIN_ID          PIN6
#define KEYPAD_THIRD_COL_PORT_ID          PORTD
#define KEYPAD_THIRD_COL_PIN_ID           PIN5
#define KEYPAD_FOURTH_COL_PORT_ID         PORTD
#define KEYPAD_FOURTH_COL_PIN_ID          PIN3

#define COL_PORT_DATA    {KEYPAD_FIRST_COL_PORT_ID,KEYPAD_SECOND_COL_PORT_ID,KEYPAD_THIRD_COL_PORT_ID,KEYPAD_FOURTH_COL_PORT_ID}
#define COL_PIN_DATA     {KEYPAD_FIRST_COL_PIN_ID,KEYPAD_SECOND_COL_PIN_ID,KEYPAD_THIRD_COL_PIN_ID,KEYPAD_FOURTH_COL_PIN_ID}



/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOW
#define KEYPAD_BUTTON_RELEASED           HIGH

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 void KEYPAD_init(void);
u8 KEYPAD_getPressedKey(void);

#endif
