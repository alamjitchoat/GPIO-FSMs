//_____________MAIN PROGRAM(.c)____________
/*
*Alamjit Choat
* 1962902
* 7/03/2020
* This program simulates a traffic light interaction with
*    a pedesterian button to cross the street.
*/

#include <stdint.h> 
#include "lab1.h"

// state idle everythings off
// state green ability to go to yellow and oscillate between red and green
// state yellow go from yellow to red
// state red delay than enter state green
enum states {green, yellow, red, idle}state;

// MAIN FUNCTION
int main(void){
  extern_switch_init();
  LED_init();
  state = green;
  while(1) {
    switch(state) {
    case green:
          LED_off3(); 
          LED_on(); 
          for (int j = 0; j < 1000000; j++) {}
          for (int j = 0; j < 1000000; j++) {}
          for (int j = 0; j < 1000000; j++) {}
          LED_off(); 
          LED_on3(); 
          for (int j = 0; j < 1000000; j++) {}
          for (int j = 0; j < 1000000; j++) {}
          for (int j = 0; j < 1000000; j++) {}
          if (GPIODATA_N == 0x4) {
              state = idle;
          } else if (GPIODATA_P == 0x08) {
              state = yellow;
          }
          break;
      case yellow:
        LED_off(); 
        LED_off3(); 
        LED_on2(); 
        for (int j = 0; j < 1000000; j++) {}
        for (int j = 0; j < 1000000; j++) {}
        for (int j = 0; j < 1000000; j++) {}
        state = red;
        break;
      case red:
        LED_off2(); 
        LED_on(); 
        for (int j = 0; j < 1000000; j++) {}
        for (int j = 0; j < 1000000; j++) {}
        for (int j = 0; j < 1000000; j++) {}
        state = green;
        if (GPIODATA_N == 0x4) {
            state = idle;
        }
        break;
      case idle:
          LED_off();
          LED_off2();
          LED_off3();
          for (int j = 0; j < 1000000; j++) {}
          if (GPIODATA_N == 0x4) {
              state = green;
          } 
          break;
      }  
   }
}

// initalizies all three LEDs
void LED_init(void) {
   volatile unsigned short delay = 0;
   RCGCGPIO |= 0x04; // activate clock for Port C
   delay++;
   delay++;
   GPIOAMSEL_C &= ~0x10; // disable analog function of PC4
   GPIODIR_C |= 0x10; // set PC4 to output
   GPIOAFSEL_C &= ~0x10; // set PC4 regular port function
   GPIODEN_C |= 0x10; // enable digital output on PC4
 
   GPIOAMSEL_Y &= ~0x20; // disable analog function of PC5
   GPIODIR_Y |= 0x20; // set PC5 to output
   GPIOAFSEL_Y &= ~0x20; // set PC5 regular port function
   GPIODEN_Y |= 0x20; // enable digital output on PC5
 
   GPIOAMSEL_G &= ~0x40; // disable analog function of PC6
   GPIODIR_G |= 0x40; // set PC6 to output
   GPIOAFSEL_G &= ~0x40; // set PC6 regular port function
   GPIODEN_G |= 0x40; // enable digital output on PC6
}

// turn on LED connected to PC4 (red)
void LED_on(void) {
   GPIODATA_C |= 0x10;
}

// turn on LED connected to PC5 (yellow)
void LED_on2(void) {
   GPIODATA_Y |= 0x20;
}

// turn on LED connected to PC6 (green)
void LED_on3(void) {
   GPIODATA_G |= 0x40;
}


// turn on LED connected to PC4 (red)
void LED_off(void) {
   GPIODATA_C &= ~0x10;
}

// turn on LED connected to PC5 (yellow)
void LED_off2(void) {
   GPIODATA_Y &= ~0x20;
}

// turn on LED connected to PC6 (green)
void LED_off3(void) {
   GPIODATA_G &= ~0x40;
}

// to initalize my two switch buttons 
void extern_switch_init(void){
   volatile unsigned short delay = 0;
   RCGCGPIO |= 0x1000; // Enable Port N Gating Clock
   delay++;
   delay++;
   GPIOAMSEL_N &= ~0x4; // Disable PN2 analog function
   GPIOAFSEL_N &= ~0x4; // Select PN2 regular port function
   GPIODIR_N &= ~0x4; // Set PN2 to input direction
   GPIODEN_N |= 0x4; // Enable PN2 digital function
 
   GPIOAMSEL_P &= ~0x08; // Disable PN3 analog function
   GPIOAFSEL_P &= ~0x08; // Select PN3 regular port function
   GPIODIR_P &= ~0x08; // Set PN3 to input direction
   GPIODEN_P |= 0x08; // Enable PN3 digital function
}

// returns input value of my first switch
unsigned long switch_input(void) {
   return (GPIODATA_N & 0x4); // 0x4 (pressed) or 0 (not pressed)
}

// returns input value of my second switch
unsigned long switch_input2(void) {
   return (GPIODATA_P & 0x08); // 0x08 (pressed) or 0 (not pressed)
}
  
