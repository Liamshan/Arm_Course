//Practice exercise and messing around with a triangle wave "warble function"

/*
#include "mbed.h"

//Define definitions
#define SPEAKER p21
#define AIN1 p15
#define AIN2 p16

//Define pwm outputs
PwmOut speaker(SPEAKER);

//Define analog inputs
AnalogIn pot1(AIN1);
AnalogIn pot2(AIN2);

//Frequency Range of Speaker
float low = 320;  //Hz
float med = 380;  //Hz
float high = 530; //Hz


// FUNCTIONS

void two_tone() {
    int i = 0;
    while (i < 2) {
        speaker = 0.3; // turn speaker on
        speaker.period(1/med); // set pitch to med tone
        wait(0.1);  // hold
        speaker = 0;
        wait(0.25);  // turn off
        i++;     //repeat twice
    }
}

void steady_tone() {
    speaker = 0.3;
    speaker.period(1/low);
    wait(1);
    speaker = 0;
}

void beeping_tone() {
    int i = 0;
    while(i < 4) {
        speaker = 0.3;
        speaker.period(1/high);
        wait(0.05);
        speaker = 0;
        wait(0.05);
        i++;
    }
}

void warble() {
    speaker = 0.3; // Set duty cycle

    // Increasing part of the waveform (climbing frequencies)
    for (float freq = low; freq <= high; freq += 10.0f) {
        speaker.period(1.0 / freq); // Set PWM frequency
        wait(0.02); // Small delay to simulate smooth climbing
    }

    // Decreasing part of the waveform (descending frequencies)
    for (float freq = high; freq >= low; freq -= 10.0f) {
        speaker.period(1.0 / freq); // Set PWM frequency
        wait(0.02); // Small delay to simulate smooth descending
    }

    speaker = 0; // Turn off the speaker after warble
}



//Main Loop
int main() {
    
    while(1) {
        
        float temp = pot1.read();
        float fan = pot2.read();

        // if condition 1
        if (temp > 0.66  && fan < 0.5) {
            two_tone();
            printf("Temp high: %f,  fan low: %f \n", temp, fan);
        }
        // if condition 2
        else if (temp >= 0.33 && temp <= 0.66  && fan > 0.5) {
            steady_tone();
            printf("Temp mid: %f,   fan high: %f \n", temp, fan);
        }
        // if condition 3
        else if (temp < 0.33 && fan > 0.75) {
            beeping_tone();
            printf("Temp low: %f,   Fan high: %f \n", temp, fan);
        }
        //else
        else {
            warble();
            printf("Idle: Temp: %f,  Fan: %f \n", temp, fan);
        }
        
        wait(1);
    }
}

*/