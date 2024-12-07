// Playing 3 notes at 50% volume

/*
#include "mbed.h"

#define SPEAKER p21

PwmOut speaker(SPEAKER);

// Note frequencies in Hz
const float NOTE_A = 440.0; // A4
const float NOTE_C = 261.63; // C4
const float NOTE_E = 329.63; // E4

// Function to set frequency
void playNote(float frequency) {
    speaker.period(1.0 / frequency); // Set period based on frequency
    speaker = 0.5; // 50% duty cycle for clear sound
}

int main() {
    while (true) {
        playNote(NOTE_A); // Play A4
        wait(1.0);        // Wait 1 second

        playNote(NOTE_C); // Play C4
        wait(1.0);        // Wait 1 second

        playNote(NOTE_E); // Play E4
        wait(1.0);        // Wait 1 second
    }
}

*/