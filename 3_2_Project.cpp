// Work in progress. trying to super loop the flow chart in module 3 project
/*

#include "mbed.h"

#define START_BUTTON p5
#define STOP_BUTTON p6
#define GUARD_LATCH p7
#define TEMP_LIMIT p8

#define READY p9
#define RUNNING p10
#define GUARD_OPEN p11
#define OVER_TEMP p12


// Define the Input pins
DigitalIn b1(START_BUTTON);
DigitalIn b2(STOP_BUTTON);
DigitalIn b3(GUARD_LATCH);
DigitalIn b4(TEMP_LIMIT);

//Define the Output pins
DigitalOut rled(READY);
DigitalOut yled(RUNNING);
DigitalOut bled(GUARD_OPEN);
DigitalOut pled(OVER_TEMP);


//Define Input/Output buses
BusIn buttonbus(TEMP_LIMIT, GUARD_LATCH, STOP_BUTTON, START_BUTTON);
BusOut ledbus(OVER_TEMP, GUARD_OPEN, RUNNING, READY);

int main () {
    int i = 0;
    while(i<10) {
        //Clear LEDs
        ledbus = 0b0000;
        wait(0.2);
        
        //Check temp & latch
        while (GUARD_LATCH==0||(TEMP_LIMIT==1)) {  //so, while the latches are in fault condition, stay in loop. when they change, you can break
            ledbus = 0b0000;  //clear all displays
            READY = !READY;   // FLash LEDs
            wait(0.2);
        }
    }
        
        
        i++;
}
    // while() loop super loop in here to run thru the flow charts
    // First thing is clear all the leds. 


*/