/*

#include "mbed.h"

// Define  the PWMs
#define SPEAKER p21
#define RED_LED p22
#define BLUE_LED p23
#define YELLOW_LED p24
// Define Analog Inputs
#define AIN1 p15
#define AIN2 p16

//Define Analog Input
AnalogIn Volume(AIN1);
AnalogIn Speed(AIN2);

//Define PWM Output for the speaker
PwmOut Speaker(SPEAKER);
PwmOut rled(RED_LED);
PwmOut bled(BLUE_LED);
PwmOut yled(YELLOW_LED);

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
#define b3 1   //quarter note = base beat * 1
#define b2 2   //half note = base beat * 2
#define b1 4   //whole note = base beat * 4

//Define the beats of the song
float note[] = {Mi,No,Mi,No,Mi,No, Mi,No,Mi,No,Mi,No, Mi,No,So,No,Do,No,Re,No,Mi,No, Fa,No,Fa,No,Fa,No,Fa,No, Fa,No,Mi,No,Mi,No,Mi,No,Mi,No,  Mi,No,Re,No,Re,No,Mi,No, Re,No,So,No};
float beat[] = {b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b3,b3,b3,b3,b2,b1, b3,b3,b3,b3,b3,b3,b3,b3, b3,b3,b3,b3,b3,b3,b3,b3,b3,b3,  b3,b3,b3,b3,b3,b3,b3,b3, b2,b2,b2,b2};

//Define the ticker timer
Ticker timer;

// Static Variables
static int k;
static float volume;
static float speed;

// ISR function
void timer_ISR() {   //if at a no note, turn speaker off
    if(k < (sizeof(note)/sizeof(float))) {  //if k is less than size of note
        if (note[k] == No) {
            Speaker = 0;
        } else {
            Speaker.period(note[k]);  //play note k
            Speaker = volume;
        }
        k++;  //increment k
    } else {
        k = 0;  //set k back to zero
    }
    
    //LED Blinks
    rled = volume;   //brightness based on volume
    bled = speed;    //brightness based on speed
    
    if (note[k] !=0)  {  // zero would divide bt zero
        yled = (1/note[k]) / 167;   //Dim based on pitch
    
    
    
    
    timer.attach(&timer_ISR, 0.1*beat[k]*(1+speed));  // default beat * beat multiplier * potentiometer speed
}


// Main Loop
int main() {
    
    //Startup routine
    printf("Do: \n");
    Speaker.period(Do);
    Speaker = 0.3;
    wait(1);
    
    printf("Fa: \n");
    Speaker.period(Fa);
    wait(1);
    
    printf("Ti: \n");
    Speaker.period(Ti);
    wait(1);
    Speaker = 0;
    
    //ISR
    timer.attach(&timer_ISR, 0.1*beat[k]);  //0.1sec default time between notes to start(default quarter note)  and longer if there is a beat multiplier
    k = 0;
    

    
    while(1) {
        volume = Volume.read();
        printf("Volume:  %f \n", volume);
        
        speed = Speed.read();
        printf("Speed:  %f \n", speed);
        wait_ms(10);
    }
    
}

*/