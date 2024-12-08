//Tank Sensor Machine Lab Solution

/*
#include "mbed.h"

//Define Speaker
#define SPEAKER p21
//Define LED
#define RED_LED p5
//Define Analog_ins
#define AIN1 p15
#define AIN2 p16


//Define Outputs
  //PwmOut
PwmOut speaker(SPEAKER);
  //DigitalOut
DigitalOut led1(RED_LED);

//Define Interrupts
   //AnalogIn
AnalogIn pot1(AIN1);
AnalogIn pot2(AIN2);


//Define Floats
float temp;
float volume;

//Frequency Range of Speaker
float low = 320;  //Hz
float med = 380;  //Hz
float high = 530; //Hz


//FUNCTIONS
    //function for doing warble
void warble() {
    led1 = 1;
    speaker = 0.3;
    speaker.period(1.0/low);  
    wait(0.25);
    speaker.period(1.0/med);
    wait(0.25);
    speaker.period(1.0/high);
    wait(0.25);
    speaker.period(1.0/med);
    wait(0.25);
    speaker.period(1.0/low);
    wait(0.25);
    speaker = 0;
    led1 = 0;
}
    
    
int main() {
    
    
    while(1) {
        //Declare Pot Values
        temp = pot1.read();
        volume = pot2.read();
        
        //If tank 
            //low Warble
        if (volume < 0.7) {
            printf("Volume Low: %f \n", volume);
            warble();  //sine wave pitch for 1s
        } 
        
        //else
            //switch statement
        else {
            if (temp > 0.66) {
                printf("Temp Too High \n");
                
                //Two-Tone
                speaker = 0.3;
                speaker.period(1.0/high);
                wait(0.25);
                speaker = 0;
                wait(0.1);
                speaker = 0.3;
                speaker.period(1.0/high);
                wait(0.25);
                speaker = 0;
            }
            else if (temp >= 0.33 && temp <= 0.66){
                printf("Temp Good \n");
                
                //Continuous Tone
                speaker = 0.3;
                speaker.period(1.0/med);
                wait(0.75);
                speaker = 0;
            }
            else if (temp < 0.33) {
                printf("Temp too low \n");
                
                //Single beep tone
                speaker = 0.3;
                speaker.period(1.0/low);
                wait(0.25);
                speaker = 0;
            }
        }
        
        wait(1);
    }
}
*/