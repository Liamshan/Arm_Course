// Working with tickers for practice

/*
#include "mbed.h"

#define BUTTON p5
#define LED p6
#define AIN p15

// Define Analog In
AnalogIn slider(AIN);

// Define LED object
DigitalOut led(LED);

// Include the ISRs
InterruptIn button(BUTTON);

// Declare ticker object
Ticker ticker;

// Declare Static Variables
static float speed;

// LED Toggle Function
void toggle_led() {
    led = !led;
    
    ticker.attach(&toggle_led, speed);
}

// Main loop
int main() {
    ticker.attach(&toggle_led, 0.5);
    
    while(1) {
        speed = slider.read();
        wait_ms(10);
    }
}
*/