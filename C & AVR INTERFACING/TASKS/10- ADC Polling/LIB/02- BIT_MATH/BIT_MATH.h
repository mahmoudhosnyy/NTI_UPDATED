/*********************************************/
/* AUTHOR : Mahmoud Hosny                    */
/* Date : 14 aug 2023                        */
/* Version : V01                             */
/*********************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(REG,BIT)   	 (REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT)   (REG&= ~(1<<BIT))
#define TOGGLE_BIT(REG,BIT)  (REG^= (1<<BIT))
#define GET_BIT(REG,BIT)     ((REG>>BIT)&1)
#define ROR_REG(REG,SHIFT)	 ( (REG>>SHIFT)| (REG<<(32-SHIFT)) )
#define ROL_REG(REG,SHIFT)	 ( (REG<<SHIFT)| (REG>>(32-SHIFT)) )

#endif