/*

#include "mbed.h"

//Define User btn & led
#define BUTTON PC_13
#define LED PA_5

//Declare Digital out
DigitalOut led(LED);

//Declare ISR
InterruptIn button(BUTTON);

//Debounce Timer
Timer debounce_timer;

//ISR
void toggle_led() {
    if (debounce_timer.elapsed_time().count() > 50) {
        led = !led;
    }
    debounce_timer.reset();
}

int main () {
    //Initialize led to be off
    led = 0;

    //Start debounce timer
    debounce_timer.start();
    
    //Define ISR
    button.rise(&toggle_led);

    //Super loop
    while(1) {
        
        ThisThread::sleep_for(100ms);  //low power sleep (this is an RTOS function)
    }
}

*/