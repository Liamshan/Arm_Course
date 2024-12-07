// Play Ode to Joy

/*
#include "mbed.h"

#define SPEAKER p21

//Define the Outputs
PwmOut speaker(SPEAKER);

//Make variables for the different notes

const float C = 261.63;
const float D = 293.66;
const float E = 329.63;
const float F = 349.23;
const float G = 392.00;

//Make a function to run note at given frequency
void play(float note) {
    speaker.period(1.0/note);   //Period (pitch)
    speaker = 0.3;           //Duty Cycle (volume)
}

//main
int main() {
    while(1) {
        
        // Play Ode to Joy
        play(E);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(E);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(F);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(G);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(G);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(F);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(E);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(D);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(C);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(C);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(D);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(E);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(E);
        wait(0.5);
        speaker = 0;
        wait(0.25);
        
        play(D);
        wait(0.25/2);
        speaker = 0;
        wait(0.25);
        
        play(D);
        wait(0.5);
        speaker = 0;
        wait(5);
    }
    
    wait_ms(100);
    
    
}
*/