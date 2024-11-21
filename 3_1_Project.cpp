// Module 3 project attempt 1
//Long switch statement
/*

#include "mbed.h"

#define BUTTON_1 p5  //on
#define BUTTON_2 p6  //off
#define BUTTON_3 p7  //latch
#define BUTTON_4 p8  //temp

#define RED_LED p9      // ready (fault if blinking)
#define YELLOW_LED p10  // on
#define BLUE_LED p11    // guard open
#define PURPLE_LED p12  // temp high


// Define the Input pins
DigitalIn b1(BUTTON_1);
DigitalIn b2(BUTTON_2);
DigitalIn b3(BUTTON_3);
DigitalIn b4(BUTTON_4);

//Define the Output pins
DigitalOut rled(RED_LED);
DigitalOut yled(YELLOW_LED);
DigitalOut bled(BLUE_LED);
DigitalOut pled(PURPLE_LED);

//Define Input/Output buses
BusIn buttonbus(BUTTON_4, BUTTON_3, BUTTON_2, BUTTON_1);
BusOut ledbus(PURPLE_LED, BLUE_LED, YELLOW_LED, RED_LED);

void ControlLED_DigitalIO ();
void ControlLED_BusIO ();


int main()
{
    while(1) {
        //ControlLED_DigitalIO ();
        ControlLED_BusIO ();
        wait(0.25);
    }
}

void ControlLED_DigitalIO (){
    rled = (b1&&b2&&b3&&b4) || (!b4 && (!b3||b2));
    yled = (b1&&b2&&b3&&b4) || (b4^b3);
    bled = b4;
}

void ControlLED_BusIO (){
    switch(buttonbus) {
        case 0: {
            ledbus = 0b1000; //Red LED on
            break;
        }
        case 1: {
            int i = 0;
            while (i < 4 && b4) {
                ledbus = 0b1001;  //blink red solid purple
                wait(0.5);
                ledbus = 0b0001;
                wait(0.5);
                i++;
            }
        }
            break;
        case 2: {
            int i = 0;
            while (i < 4 &&  b3  && !b4) {  //blink red solid blue
                ledbus = 0b1010;
                wait(0.5);
                ledbus = 0b0010;
                wait(0.5);
                i++;
            }
        }
            break;
        case 3: {
            int i = 0;
            while (i < 4 && b4) {  // blink red solid blue/purple
                ledbus = 0b1011;
                wait(0.5);
                ledbus = 0b0011;
                wait(0.5);
                i++;
            }
        }
            break;
        case 4: 
            ledbus = 0b1000;    
            break;
        case 5: {
            int i = 0;
            while (i < 4 && b4) {
            ledbus = 0b1001;  //blink red solid purple
            wait(0.5);
            ledbus = 0b0001;
            wait(0.5);
            i++;  
            }
        }
            break;
        case 6: {
            int i = 0;
            while (i < 4 &&  b3  && !b4) {  //blink red solid blue
                ledbus = 0b1010;
                wait(0.5);
                ledbus = 0b0010;
                wait(0.5);
                i++;
            }
        }
            break;
        case 7: {
            int i = 0;
            while (i < 4 && b4) {  // blink red solid blue/purple
                ledbus = 0b1011;
                wait(0.5);
                ledbus = 0b0011;
                wait(0.5);
                i++;
            }
        }
            break;
        case 8:
            ledbus = 0b0100;     // YELLOW ON: The only working state of the machine
            break;
        
        // Just copy cases 1-7 becuase 9-15 are the same. 
        
        case 9: {
            int i = 0;
            while (i < 4 && b4) {
                ledbus = 0b1001;  //blink red solid purple
                wait(0.5);
                ledbus = 0b0001;
                wait(0.5);
                i++;
            }
        }
            break;
        case 10: {
            int i = 0;
            while (i < 4 &&  b3  && !b4) {  //blink red solid blue
                ledbus = 0b1010;
                wait(0.5);
                ledbus = 0b0010;
                wait(0.5);
                i++;
            }
        }
            break;
        case 11: {
            int i = 0;
            while (i < 4 && b4) {  // blink red solid blue/purple
                ledbus = 0b1011;
                wait(0.5);
                ledbus = 0b0011;
                wait(0.5);
                i++;
            }
        }
            break;
        case 12: 
            ledbus = 0b1000;    
            break;
        case 13: {
            int i = 0;
            while (i < 4 && b4) {
            ledbus = 0b1001;  //blink red solid purple
            wait(0.5);
            ledbus = 0b0001;
            wait(0.5);
            i++;  
            }
        }
            break;
        case 14: {
            int i = 0;
            while (i < 4 &&  b3  && !b4) {  //blink red solid blue
                ledbus = 0b1010;
                wait(0.5);
                ledbus = 0b0010;
                wait(0.5);
                i++;
            }
        }
            break;
        case 15: {
            int i = 0;
            while (i < 4 && b4) {  // blink red solid blue/purple
                ledbus = 0b1011;
                wait(0.5);
                ledbus = 0b0011;
                wait(0.5);
                i++;
            }
        }
            break;
    
        default: ;
    }
}

/*
ok, this is an attempt to do the module 3 project assignment on my own without guidance. I decided to do a
really long switch statement similar to the one we did in the example lesson. it works but isn't elegant. 
it handles each of the 15 configurations of the on, off, latch, and temperature switch.

The objective was to assign different led stated to account for different states of the machine (on, off, overtemp, safety latch open)
so what i did was turned the (on, off, temp, latch) conditions as switches
then I set each of the warning states as leds (red=ready, yellow=on, blue=latch open, purple=temp high) also we would have red flash if there was a fault preventing it from turning on (eg, blue or purple were on)
so I turned the 4 button states into 4 bit bus called "buttonbus". and the 4 leds into "ledbus"
I then needed to know all the permutations of button positions. So i made a binary table counting from 0 to 15
to account for all of the possible combinations. for example buttonbus = 0b0000 means no buttons were pressed and therefor would result in ledbus=0b1000 meaning only the red (ready) led would be on
I did this for all combinations. then I made the switch statement read buttonbus and write to ledbus. 

an example of the on button being on and there being no faults would be buttonbus==0b1000 and ledbus=0b0100 to turn on the yellow "on" led. 





URL for the simulator module (must be running sim on docker for this to work): http://localhost:7829/#user_1732179275554
Here is the link to the lesson: https://learning.edx.org/course/course-v1:ArmEducation+EDARMXES1.6x+3T2020/block-v1:ArmEducation+EDARMXES1.6x+3T2020+type@sequential+block@6261dd84212149bb856fbd69977050c6/block-v1:ArmEducation+EDARMXES1.6x+3T2020+type@vertical+block@9d8ed3c9913f4aada252068e5296913f

*/
























