/*
//UART Demo. Sends message to PC terminal


#include "mbed.h"
BufferedSerial pc(USBTX, USBRX,9600);
int cycle = 0;

int main() {
    while(true) {
        printf("Hello World. This is loop %i \n\r",cycle);
        thread_sleep_for(500);
        cycle++;
    }
}

*/