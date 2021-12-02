/*
*Alamjit Choat
* 1962902
* 7/03/2020
* This program lights up LED1 when SW1 is pressed and
*  lights up LED2 when SW2 is pressed.    
*/

#include <stdint.h>
#include "lab1.h"


int main(void) {  
   volatile unsigned short delay = 0;
   RCGCGPIO |= 0x1120; 
   delay++; // Delay 2 more cycles before access Timer registers
   delay++; // Refer to Page. 756 +-of Datasheet for info
 
   GPIODIR_J = 0x00;
   GPIODIR_N = 0x03;
 
   GPIODEN_J = 0x03;
   GPIODEN_N = 0x03;
 
   GPIOPUR_J = 0x03; 
 

   while (1) {
      if (GPIODATA_J == 0x01) {
         GPIODATA_N = 0x01;
      } else if (GPIODATA_J == 0x02) {
         GPIODATA_N = 0x02;
      } else {
         GPIODATA_N = 0x0; 
      }
   }
}
