/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 31 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/***************************************************************/
typedef struct {
	u32 HSION:1;
	u32 HISRDY:1;
	u32 :1;
	u32 HSITRIM:5;
	u32 HSICAL:8;
	u32 HSEON:1;
	u32 HSERDY:1;
	u32 HSEBYP:1;
	u32 CSSON:1;
	u32 :4;
	u32 PLLON:1;
	u32 PLLRDY:1;
	u32 :6;
}RCC_CR;

#define RCC_CR_REG      ((volatile u32*)0x40021000)

typedef enum {
	PLL_x2=0b0000,
	PLL_x3=0b0001,
	PLL_x4=0b0010,
	PLL_x5=0b0011,
	PLL_x6=0b0100,
	PLL_x7=0b0101,
	PLL_x8=0b0110,
	PLL_x9=0b0111,
	PLL_x10=0b1000,
	PLL_x11=0b1001,
	PLL_x12=0b1010,
	PLL_x13=0b1011,
	PLL_x14=0b1100,
	PLL_x15=0b1101,
	PLL_x16=0b1110,
	PLL_x16_2=0b1111,
}MULTI_FACTOR;

/***************************************************************/
typedef struct {
	u32 SW:2;
	u32 SWS:2;
	u32 HPRE:4;
	u32 PPRE1:3;
	u32 PPRE2:3;
	u32 ADCPRE:2;
	u32 PLLSRC:1;
	u32 PLLXTRPE:1;
	u32 PLLMUL:4;
	u32 USBPRE:1;
	u32 :1;
	u32 MCO:3;
	u32 :5;
}RCC_CFGR;

#define RCC_CFGR_REG      ((volatile u32*)0x40021004)
/***************************************************************/
typdef struct {
	u32 LSIRDYF:1;
	u32 LSERDYF:1;
	u32 HSIRDYF:1;
	u32 HSERDYF:1;
	u32 PLLRDYF:1;
	u32 :2;
	u32 CSSF:1;
	u32 LSIRDYIE:1;
	u32 LSERDYIE:1;
	u32 HSIRDYIE:1;
	u32 HSERDYIE:1;
	u32 PLLRDYIE:1;
	u32 :3;
	u32 LSIRDYC:1;
	u32 LSERDYC:1;
	u32 HSIRDYC:1;
	u32 HSERDYC:1;
	u32 PLLRDYC:1;
	u32 :2;
	u32 CSSC:1;
	u32:8;	
}RCC_CIR;

#define RCC_CIR_REG    ((volatile u32*)0x40021008)
/***************************************************************/
#define RCC_APB2RSTR_REG   *((volatile u32*)0x4002100C)

#define    AFIORST         0
#define    GPIOARST        2
#define    GPIOBRST        3
#define    GPIOCRST        4
#define    GPIODRST        5
#define    GPIOERST        6
#define    GPIOFRST        7
#define    GPIOGRST        8
#define    ADC1RST         9
#define    ADC2RST         10
#define    TIM1RST         11
#define    SPI1RST         12
#define    TIM8RST         13
#define    USART1RST       14
#define    ADC3RST         15
#define    TIM9RST         19
#define    TIM10RST        20
#define    TIM11RST        21
/***************************************************************/
#define RCC_APB1RSTR_REG     *((volatile u32*)0x40021010)

#define    TIM2RST         0
#define    TIM3RST         1
#define    TIM4RST         2
#define    TIM5RST         3
#define    TIM6RST         4
#define    TIM7RST         5
#define    TIM12RST        6
#define    TIM13RST        7
#define    TIM14RST        8
#define    WWDGRST         11
#define    SPI2RST         14
#define    SPI3RST         15
#define    USART2RST       17
#define    USART3RST       18
#define    UART4RST        19
#define    UART5RST        20
#define    I2C1RST         21
#define    I2C2RST         22
#define    USBRST          23
#define    CANRST          25
#define    BKPRST          27
#define    PWRRST          28
#define    DACRST          29
/***************************************************************/
#define RCC_AHBENR_REG    *((volatile u32*)0x40021014)

#define    DMA1EN         0
#define    DMA2EN         1
#define    SRAMEN         2
#define    FLITFEN        4
#define    CRCEN          6
#define    FSMCEN         8
#define    SDIOEN         10
/***************************************************************/
#define RCC_APB2ENR_REG    *((volatile u32*)0x40021018)

#define    AFIOEN         0
#define    GPIOAEN        2
#define    GPIOBEN        3
#define    GPIOCEN        4
#define    GPIODEN        5
#define    GPIOEEN        6
#define    GPIOFEN        7
#define    GPIOGEN        8
#define    ADC1EN         9
#define    ADC2EN         10
#define    TIM1EN         11
#define    SPI1EN         12
#define    TIM8EN         13
#define    USART1EN       14
#define    ADC3EN         15
#define    TIM9EN         19
#define    TIM10EN        20
#define    TIM11EN        21
/***************************************************************/
#define RCC_APB1ENR_REG     *((volatile u32*)0x4002101C)

#define    TIM2EN         0
#define    TIM3EN         1
#define    TIM4EN         2
#define    TIM5EN         3
#define    TIM6EN         4
#define    TIM7EN         5
#define    TIM12EN        6
#define    TIM13EN        7
#define    TIM14EN        8
#define    WWDGEN         11
#define    SPI2EN         14
#define    SPI3EN         15
#define    USART2EN       17
#define    USART3EN       18
#define    UART4EN        19
#define    UART5EN        20
#define    I2C1EN         21
#define    I2C2EN         22
#define    USBEN          23
#define    CANEN          25
#define    BKPEN          27
#define    PWREN          28
#define    DACEN          29
/***************************************************************/

typedef struct {
	u32 LSEON:1;
	u32 LSERDY:1;
	u32 LSEBYP:1;
	u32 :5;
	u32 RTCSEL:2;
	u32 :5;
	u32 RTCEN:1;
	u32 BDRST:1;
	u32 :15;
}RCC_BDCR;

#define RCC_BDCR_REG       ((volatile u32*)0x40021020)
/***************************************************************/

typedef struct {
	u32 LSION:1;
	u32 LSIRDY:1;
	u32 :22;
	u32 RMVF:1;
	u32 :1;
	u32 PINRSTF:1;
	u32 PORRSTF:1;
	u32 SFTRSTF:1;
	u32 IWDGRSTF:1;
	u32 WWDGRSTF:1;
	u32 LPWRRSTF:1;
}RCC_CSR;

#define RCC_CSR_REG       ((volatile u32*)0x40021024)
/***************************************************************/

#define    AHB_BUS       0
#define    APB1_BUS      1
#define    APB2_BUS      2

#define HSI           0
#define HSE           1
#define PLL           2
#define HSE_BYPASS    3

#define PLL_HSI_DIVIDED_BY_2    0
#define PLL_HSE                 1
#define PLL_HSE_DIVIDED_BY_2    2

#define ENABLE_CLOCK_SECURITY_SYSTEM  0
#define DISABLE_CLOCK_SECURITY_SYSTEM 1


#endif 