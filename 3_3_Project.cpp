/*  This is first successful Super Loop

#include "mbed.h"

// This is the second attempt at the super loop
// Inputs
DigitalIn START(p5);
DigitalIn STOP(p6);
DigitalIn GUARD(p7);  // 0 if open
DigitalIn TEMP(p8);   // 1 if overtemp

//Outputs
DigitalOut READY(p9);
DigitalOut RUNNING(p10);
DigitalOut LATCH_OPEN(p11);
DigitalOut OVERTEMP(p12);

int main() {
    while(true) {
        
    // State 1: Clear LEDs / check for faults
        READY = RUNNING = LATCH_OPEN = OVERTEMP = 0;  //clear LEDs
        while(GUARD == 0 || TEMP == 1) {  // While fault condition is true
            //flash red LED
            READY = !READY;
            wait(0.5);
        }
    
    // State 2: switch on ready, then standby loop waiting for btn press
        while(START == 0) {
            READY = 1; //Standby light is on
            wait(0.05); //Just chilling until button is pressed
        }
    // State 3: Switch on, while there are no faults
        while(STOP == 0 && GUARD == 1 && TEMP == 0) {
            READY = 0;
            RUNNING = 1;
            wait(0.05);
        }
    
    // State 4: you've exited because of a fault, if statements to sus out the fault
        if (GUARD == 0) {
            LATCH_OPEN = 1;
            wait(0.9);
            LATCH_OPEN = 0;
        }
        
        if (TEMP == 1) {
            OVERTEMP = 1;
            wait(0.9);
            OVERTEMP = 0;
        }
        
        if (STOP == 1) {
            //Just exit
        }
        wait(0.2);   // Just incase we accidentally break from the loop in a condition that skipps all while loops and gets stuck in an a busy loop
    }
    
}

*/