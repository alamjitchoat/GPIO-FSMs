//___________HEADER FILE(.h) ___________
/*
*Alamjit Choat
* 1962902
* 7/03/2020
* Header file for my main program
*/

#ifndef __HEADER1_H__
#define __HEADER1_H__

// to turn on red LED
#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define GPIOAMSEL_C (*((volatile uint32_t *)0x4005A528))
#define GPIODIR_C (*((volatile uint32_t *)0x4005A400))
#define GPIODEN_C (*((volatile uint32_t *)0x4005A51C))
#define GPIOAFSEL_C (*((volatile uint32_t *)0x4005A420))
#define GPIODATA_C (*((volatile uint32_t *)0x4005A3FC))

// to turn on yellow LED
#define GPIOAMSEL_Y (*((volatile uint32_t *)0x4005A528))
#define GPIODIR_Y (*((volatile uint32_t *)0x4005A400))
#define GPIODEN_Y (*((volatile uint32_t *)0x4005A51C))
#define GPIOAFSEL_Y (*((volatile uint32_t *)0x4005A420))
#define GPIODATA_Y (*((volatile uint32_t *)0x4005A3FC))

// to turn on green LED
#define GPIOAMSEL_G (*((volatile uint32_t *)0x4005A528))
#define GPIODIR_G (*((volatile uint32_t *)0x4005A400))
#define GPIODEN_G (*((volatile uint32_t *)0x4005A51C))
#define GPIOAFSEL_G (*((volatile uint32_t *)0x4005A420))
#define GPIODATA_G (*((volatile uint32_t *)0x4005A3FC))

// to activate switch #1
#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define GPIOAMSEL_N (*((volatile uint32_t *)0x40064528))
#define GPIODIR_N (*((volatile uint32_t *)0x40064400))
#define GPIODEN_N (*((volatile uint32_t *)0x4006451C))
#define GPIOAFSEL_N (*((volatile uint32_t *)0x40064420))
#define GPIODATA_N (*((volatile uint32_t *)0x400643FC))

// to activate switch #2
#define GPIOAMSEL_P (*((volatile uint32_t *)0x40064528))
#define GPIODIR_P (*((volatile uint32_t *)0x40064400))
#define GPIODEN_P (*((volatile uint32_t *)0x4006451C))
#define GPIOAFSEL_P (*((volatile uint32_t *)0x40064420))
#define GPIODATA_P (*((volatile uint32_t *)0x400643FC))

// initalizies LEDS and switches 
void LED_init(void);
void extern_switch_init(void);

// returns input values for two switches
unsigned long switch_input(void);
unsigned long switch_input2(void);

// turns on all three LEDs
void LED_on(void);
void LED_on2(void);
void LED_on3(void);

// turns off all three LEDS
void LED_off(void);
void LED_off2(void);
void LED_off3(void);

#endif //__HEADER1_H__
