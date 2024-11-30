//Another attempt
/*
#include "mbed.h"

#define ADULT_BUTTON p5


#define BLUE_LED p9
#define YELLOW_LED p10
#define WHITE_LED p11

//Define outputs
DigitalOut bled(BLUE_LED);
DigitalOut yled(YELLOW_LED);
DigitalOut wled(WHITE_LED);


//Define interrupt inputs
InterruptIn adult_btn(ADULT_BUTTON);

//Define counters
volatile unsigned int count1;

void updateLEDs(){
    //Write your code here
}


//Define ISRs for the interrupts
void button_1_handler(){
    // turn on waiting room led if there is space.
    if (bled == 0) {
        bled = 1;
    }
	
}

void button_2_handler(){
	
	//Write your code here
	
}

void button_3_handler(){
	
	//Write your code here
	
}

void button_4_handler(){
    bled = 0;
    wled = 0;
    count1 = 0;
	
}


int main(){
		
	//Initially turn off all LEDs and set all the counters to 0
    button_4_handler();

	//Interrupt handlers
	adult_btn.rise(&button_1_handler);
	
	

	//wait 100 ms
	while(1) {
	    // Add customer to barber
	    if (bled == 1 && yled == 0) {
	        yled = 1;
	        bled = 0;
	        count1 = 0;
	    }
	    if (count1 <= 12) {   //only tick if less than 12
	        count1++;
	        wled = !wled;
	    }
	    if (count1 == 12) {   //clear the chair after 12 secs
	        yled = 0;
	    }
	    printf("count1: %u\n", count1);
		wait(1);  
	}
	
}

*/