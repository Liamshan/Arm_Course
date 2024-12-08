//Adjustable Speaker pitch and volume with PWM
/*
#include "mbed.h"

#define SPEAKER p21
#define AIN1 p15
#define AIN2 p16

// Define the PWM speaker output
PwmOut speaker (SPEAKER);

//Write your code here
AnalogIn pot1(AIN1);
AnalogIn pot2(AIN2);


//Define variables
float val1;
float val2;
float i;
float hz;
int main(){
    while(1){
        val1 = pot1.read();
        val2 = pot2.read();
        
        // Create a saw-tooth sound wave
        // Make the period and volume adjustable using the potentiometers
        for(i = 0; i < 1; i += 0.05){
            speaker.period(0.003125-(0.002*val1));
            speaker = i * 0.05 * val2;
            hz = 1/(0.003125-(0.002*val1));
            printf("the frequency is %f\n", hz);  // Print out the frequency
        }
        
        wait_ms(100);
    }
}


*/