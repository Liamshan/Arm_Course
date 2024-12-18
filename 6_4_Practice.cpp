//Truing to get timer to work

/*
#include "mbed.h"

//define the button
#define BUTTON p5

// Make button object
InterruptIn button(BUTTON);

// Initialize Timer
Timer timer;

// ISR
void on_button_pressed() {     //start a press timer
    timer.reset();   //reset the timer
    timer.start();   //start the timer
}
void on_button_released() {
    timer.stop();    //stop the timer
    printf("Button pressed for: %f seconds\n", timer.read());  // read timer
}


int main() {
    timer.start();
    
    button.fall(&on_button_pressed);   //when btn press
    button.rise(&on_button_released);  //when btn release
        
    while(1) {
        wait_ms(10);
    }
}
*/