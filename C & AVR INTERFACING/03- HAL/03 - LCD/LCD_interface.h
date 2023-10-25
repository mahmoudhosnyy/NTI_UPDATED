/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 21 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 PORTA
#define LCD_RS_PIN_ID                  PIN3

#define LCD_EN_PORT_ID                  PORTA
#define LCD_EN_PIN_ID                   PIN2

#define LCD_DATA_PORT_ID               PORTB

#define LCD_DB4_PIN_ID                 PIN0
#define LCD_DB5_PIN_ID                 PIN1
#define LCD_DB6_PIN_ID                 PIN2
#define LCD_DB7_PIN_ID                 PIN4



/* LCD Commands */
#define LCD_CLEAR_DISPLAY              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void);

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(u8 command);

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(u8 data);

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(u8 row,u8 col);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(u8 row,u8 col,const char *Str);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data);

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void);

#endif
