// Rough first attempt at ISR problem

/*
#include "mbed.h"

#define ADULT_INPUT p5
#define CHILD_INPUT p6 
#define FIRE_INPUT p7 

#define WAITING_1 p11
#define WAITING_2 p12
#define WAITING_3 p13
#define WAITING_4 p14
#define WAITING_5 p15
#define WAITING_6 p16
#define WAITING_7 p17
#define WAITING_8 p18

#define BARBER_1 p21
#define BARBER_2 p22
#define BARBER_3 p23

#define FIRE_ALARM p24

//Define output
DigitalOut led1(WAITING_1);
DigitalOut led2(WAITING_2);
DigitalOut led3(WAITING_3);
DigitalOut led4(WAITING_4);
DigitalOut led5(WAITING_5);
DigitalOut led6(WAITING_6);
DigitalOut led7(WAITING_7);
DigitalOut led8(WAITING_8);

DigitalOut led21(BARBER_1);
DigitalOut led22(BARBER_2);
DigitalOut led23(BARBER_3);

DigitalOut led24(FIRE_ALARM);

//Define Interrupt Inputs
InterruptIn button_1(ADULT_INPUT);
InterruptIn button_2(CHILD_INPUT);
InterruptIn button_3(FIRE_INPUT);

//Define Adult Bus
BusOut waiting_bus(WAITING_1, WAITING_2, WAITING_3, WAITING_4, WAITING_5, WAITING_6, WAITING_7, WAITING_8);

//Define counters
volatile unsigned int count1;  // Adult waiting room counter
volatile unsigned int count2;  // Child waiting room counter
volatile unsigned int count3;  // Barber chair counter


void updateLEDs(){
    led1 = 0;
	led2 = 0;
	led3 = 0;
    
    if(count1==countmax)led1=1;
    if(count2==countmax)led2=1;
    if(count3==countmax)led3=1;

}

//Define ISRs for interrupts
void button_1_handler(){  // ADULTS
	count1++;
    if(count1>countmax) countmax=count1;
    updateLEDs();
}

void button_2_handler(){  // CHILDREN
    count2++;
    if(count2>countmax) countmax=count2;    
    updateLEDs();
    }

void button_3_handler(){  
    count3++;
    if(count3>countmax) countmax=count3;
    updateLEDs();
    }

void button_4_handler(){
    led1 = 0;
	led2 = 0;
	led3 = 0;

	count1=0; 
    count2=0;
    count3=0;
}

int main(){
		
	//Initially turn off all LEDs and set all the counters to 0
    button_4_handler();

	//Interrupt handlers
	button_1.rise(&button_1_handler);
	button_2.rise(&button_2_handler);
	button_3.rise(&button_3_handler);
	button_4.rise(&button_4_handler);
	
	//wait 100 ms
	while(1)
		wait_ms(100);
}
*/