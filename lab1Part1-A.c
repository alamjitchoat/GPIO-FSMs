/*
*Alamjit Choat
* 1962902
* 7/03/2020
* This program creates a sequential LED pattern
*    using the TIVA board.
*/

#include <stdint.h> 
#include "lab1.h"

int main(void){

  LED_init();
  while(1){
     LED_on();
     for (int j = 0; j < 1000000; j++) {}
     LED_off();
  }

   void LED_on(void) {
     GPIODIR_F = 0x01;
     GPIODEN_F = 0x01; 
     GPIODATA_F = 0x01;
     
     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}

     GPIODIR_F = 0x11;
     GPIODEN_F = 0x11; 
     GPIODATA_F = 0x11;

     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}

     GPIODIR_N = 0x01;
     GPIODEN_N = 0x01;
     GPIODATA_N = 0x01;

     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}

     GPIODIR_N = 0x03;
     GPIODEN_N = 0x03;
     GPIODATA_N = 0x03;

     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}
  }
  
  void LED_off(void) {
     GPIODIR_N = 0x01;
     GPIODEN_N = 0x01;
     GPIODATA_N = 0x01;

     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}

     GPIODATA_N = 0x00;

     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}

     GPIODIR_F = 0x01;
     GPIODEN_F = 0x01; 
     GPIODATA_F = 0x01;

     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}

     GPIODIR_F = 0x00;
     GPIODEN_F = 0x00; 
     GPIODATA_F = 0x00;

     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {}
     for (int j = 0; j < 1000000; j++) {} 
  }
  
  void LED_init(void){
     volatile unsigned short delay = 0;
     RCGCGPIO  |= 0x1120;    
     delay++;
     delay++;

     GPIODIR_F = 0x11;  
     GPIODEN_F = 0x11;  
     GPIODATA_F = 0x01; 

     GPIODIR_N = 0x03;     
     GPIODEN_N = 0x03;      

     GPIODIR_J = 0x00;      
     GPIODEN_J = 0x03;      
     GPIOPUR_J = 0x03;  
  }
}
