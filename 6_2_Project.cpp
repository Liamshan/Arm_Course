
/*
You left off trying to set up the ISR to figure out how to
parse thru the "note" array at the correct speed. 
*/




/*

#include "mbed.h"

// Define  the PWMs
#define SPEAKER p21
#define RED_LED p22
#define YELLOW_LED p23
#define BLUE_LED p24
// Define Analog Inputs
#define AIN1 p15
#define AIN2 p16

//Define PWM Output for the speaker
PwmOut Speaker(SPEAKER);

//Define the notes of the song
#define Do (1.0/100.0) //hz
#define Re (1.0/111.0) //hz
#define Mi (1.0/125.0) //hz
#define Fa (1.0/139.0) //hz
#define So (1.0/152.0) //hz
#define La (1.0/161.0) //hz
#define Ti (1.0/167.0) //hz
#define No 0 //hz

//Define the beats of the song
float note[] = {Mi,No,Mi,No,Mi,No, Mi,No,Mi,No,Mi,No, Mi,No,So,No,Do,No,Re,No,Mi,No, Fa,No,Fa,No,Fa,No,Fa,No, Fa,No,Mi,No,Mi,No,Mi,No,Mi,No,  Mi,No,Re,No,Re,No,Mi,No, Re,No,So,No};
float beat[] = {b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b3,b3,b3,b3,b2,b1, b3,b3,b3,b3,b3,b3,b3,b3, b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,  b3,b3,b3,b3,b3,b3,b3,b3, b2,b2,b2,b2};

//Define the ticker timer
Ticker timer;


// ISR function



// Main Loop
int main() {
    
    timer.attach(&timer_ISR, 0.1);  //0.1sec default time between notes to start
    k = 0;
    
    //Startup routine
    printf("Do: \n");
    Speaker.period(do);
    Speaker = 0.3;
    wait(1);
    
    printf("Fa: \n");
    Speaker.period(fa);
    wait(1);
    
    printf("Ti: \n");
    Speaker.period(ti);
    wait(1);
    Speaker = 0;
    
    while(1) {
        wait_ms(10);
    }
    
}



*/