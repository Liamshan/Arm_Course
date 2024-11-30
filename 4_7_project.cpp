// With BusOut Bit Manipulation for the waiting room leds
/*
#include "mbed.h"

#define ADULT_BUTTON p5
#define CHILD_BUTTON p6
#define FIRE_ALARM_BUTTON p8

#define BARBER1_LED p9
#define BARBER2_LED p10
#define BARBER3_LED p11

#define WAITING_LED1 p12
#define WAITING_LED2 p13
#define WAITING_LED3 p14
#define WAITING_LED4 p15
#define WAITING_LED5 p16
#define WAITING_LED6 p17
#define WAITING_LED7 p18
#define WAITING_LED8 p19


//Define Output
DigitalOut barber1_led(BARBER1_LED);
DigitalOut barber2_led(BARBER2_LED);
DigitalOut barber3_led(BARBER3_LED);
//Define BusOut
BusOut waiting_leds (WAITING_LED1, WAITING_LED2, WAITING_LED3, WAITING_LED4, WAITING_LED5, WAITING_LED6, WAITING_LED7, WAITING_LED8);
//Define Interrupts
InterruptIn adult_button(ADULT_BUTTON);
InterruptIn child_button(CHILD_BUTTON);
InterruptIn fire_alarm_button(FIRE_ALARM_BUTTON);

//Counters
volatile unsigned int adult_counter;
volatile unsigned int child_counter;
volatile unsigned int parent_counter;
volatile unsigned int count1;
volatile unsigned int count2;
volatile unsigned int count3;
volatile unsigned int waitingroom_counter;


//Handlers
void adult_button_handler() {
    if(waitingroom_counter < 8) {
        adult_counter++;  //add to waiting room when btn press
    } else {
        printf("**waiting room is full*\n");
    }
}

void child_button_handler() {
    if(waitingroom_counter < 7) { //7 cuz need 2 spaces
        child_counter++;
        parent_counter++;
    } else {
        printf("*waiting room is full*\n");
    }
}

void fire_alarm_handler() {
    barber1_led = 0;
    barber2_led = 0;
    barber3_led = 0;
    adult_counter = 0;
    child_counter = 0;
    parent_counter = 0;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    waiting_leds = 0;
}

//Functions
void update_waiting_leds() {
    waiting_leds = (1 << waitingroom_counter) - 1;
}


int main(){
    //Initialize
    fire_alarm_handler();
    
    //handlers
    adult_button.rise(&adult_button_handler);
    child_button.rise(&child_button_handler);
    fire_alarm_button.rise(&fire_alarm_handler);
    
    while(1) {
        // Barber 1 Loop
        if (barber1_led == 0 && adult_counter > 0) { //if barber 1 chair is empty and there is availabe adults
            barber1_led = 1;  //fill seat
            adult_counter--;  //remove from waiting room
            count1 = 12;      //start timer
        }
        else if (barber1_led == 1) { //decrement timer if seat is full (elseif means will wait a full loop after seat has been filled before checking)
            count1--;
            if (count1 == 0) {  //if timer runs out
                barber1_led = 0; // turn barber led off and exit
            }
        }
        // Barber 2 Loop
        if (barber2_led == 0 && adult_counter > 0) {
            barber2_led = 1;
            adult_counter--;
            count2 = 12;
        }
        else if (barber2_led == 1) {
            count2--;
            if (count2 == 0) {
                barber2_led = 0;
            }
        }
        // Barber 3 Loop
        if (barber3_led == 0 && child_counter > 0) { //>1 because if there is 1 person then it's the child's parent.
            barber3_led = 1;
            child_counter--; // remember to remove parent later can only subtract 1 becuase parent is waiting
            count3 = 12;
        }
        else if (barber3_led == 1) {
            count3--;
            if (count3 == 0) {
                barber3_led = 0;
                parent_counter--;  //remove parent when child leaves. 
            }
        }
        
        waitingroom_counter = adult_counter + child_counter + parent_counter;
        
        update_waiting_leds();
        
        printf("count1/2/3: %u, %u, %u \n", count1, count2, count3);
        printf("waiting room: %u \n\n", waitingroom_counter);
        wait(1);
    }
}














*/