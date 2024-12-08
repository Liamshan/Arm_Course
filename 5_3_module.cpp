// Hot Crossed Buns (Because these are the frequencies that actually work)

/*
#include "mbed.h"

#define SPEAKER p21

//Define the Outputs
PwmOut speaker(SPEAKER);

//Make variables for the different notes

const float E = 320;
const float D = 380;
const float C = 530;

//Make a function to run note at given frequency
void play(float note) {
    speaker.period(1.0/note);   //Period (pitch)
    speaker = 0.3;           //Duty Cycle (volume)
}

//main
int main() {
    while(1) {
        
        // Play Hot Cross Buns
        play(E);
        wait(0.5);
        speaker = 0;
        wait(0.25);
        
        play(D);
        wait(0.5);
        speaker = 0;
        wait(0.25);
        
        play(C);
        wait(0.5);
        speaker = 0;
        wait(0.5);
        
        play(E);
        wait(0.5);
        speaker = 0;
        wait(0.25);
        
        play(D);
        wait(0.5);
        speaker = 0;
        wait(0.25);
        
        play(C);
        wait(0.5);
        speaker = 0;
        wait(0.5);
        //_________
        play(C);
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
        
        play(C);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(D);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(D);
        wait(0.25);
        speaker = 0;
        wait(0.25);
        
        play(D);
        wait(0.5);
        speaker = 0;
        wait(0.25);
        
        play(D);
        wait(0.25/2);
        speaker = 0;
        wait(0.25);
        //___________________
        
        play(E);
        wait(0.5);
        speaker = 0;
        wait(0.25);
        
        play(D);
        wait(0.5);
        speaker = 0;
        wait(0.25);
        
        play(C);
        wait(0.5);
        speaker = 0;
        wait(5);
    }
    
    wait_ms(100);
    
    
}

*/