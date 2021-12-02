/*
*Alamjit Choat
* 1962902
* 7/03/2020
* Header file for Task 1 part A   
*/

#ifndef __HEADER1_H__
#define __HEADER1_H__
#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define GPIODIR_J (*((volatile uint32_t *)0x40060400))
#define GPIODIR_N (*((volatile uint32_t *)0x40064400))
#define GPIODIR_F (*((volatile uint32_t *)0x4005D400)) 


#define GPIODEN_J (*((volatile uint32_t *)0x4006051C))
#define GPIODEN_N (*((volatile uint32_t *)0x4006451C))
#define GPIODEN_F (*((volatile uint32_t *)0x4005D51C)) 

#define GPIOPUR_J (*((volatile uint32_t *)0x40060510))

#define GPIODATA_J (*((volatile uint32_t *)0x400603FC))
#define GPIODATA_N (*((volatile uint32_t *)0x400643FC))
#define GPIODATA_F (*((volatile uint32_t *)0x4005D3FC)) 

void LED_init(void);
void LED_off(void);
void LED_on(void);


#endif //__HEADER1_H__
