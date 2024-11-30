// Traffic Light Problem
//with ISR & bit manipulation practice
/* 
#include "mbed.h"

#define PEDESTRIAN_BTN p5

#define WHITE_LED p9
#define RED_LED p10
#define YELLOW_LED p11
#define GREEN_LED p12

//Outputs
DigitalOut rled(RED_LED);
DigitalOut yled(YELLOW_LED);
DigitalOut gled(GREEN_LED);
DigitalOut wled(WHITE_LED);

//Bus
BusOut ledbus(GREEN_LED, YELLOW_LED, RED_LED, WHITE_LED);

//Interrupts
InterruptIn pedestrian_btn(PEDESTRIAN_BTN);


//Handlers
void clear_led_handler() {
    rled = 0;
    yled = 0;
    gled = 0;
    wled = 0;
}

void crosswalk_handler() {
    while (ledbus < 0b1000) {
        ledbus = ledbus << 1;
        wait(5);
    }
    ledbus = 0b0001;
    wait(5); //Back to green
}


int main() {
    clear_led_handler();
    pedestrian_btn.rise(&crosswalk_handler);
    
    while(1) {
        //Initual Contition
        ledbus = 0b0001;
        wait(5);
        
        //Traffic Sequence
        while (ledbus < 0b0100) {
            ledbus = ledbus << 1;
            wait(5);
        }
        //rled = 0;
        //gled = 1;
        //ledbus = 0b0001;
        //wait(5);
        
        //gled = 0;
        //yled = 1;
        //ledbus = 0b0010;
        //ledbus = ledbus << 1;
        //wait(5);
        
        //yled = 0;
        //rled = 1;
        //ledbus = 0b0100;
        //ledbus = << ledbus;
        //ledbus = ledbus << 1;
        //wait(5);
    }
    
    
}
*/