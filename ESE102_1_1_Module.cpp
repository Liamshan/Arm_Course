//Objective, to pass values to a shift register and display that number with LEDs.

/* 

#include "mbed.h"

DigitalOut CS(D10);
SPI ser_port(D11, D12, D13);  //mosi, miso, sclk
char switch_word;  //word we will send

int main() {
    ser_port.format(8,0);     // Set up the SPI for 8 bit data & mode 0 operation
    ser_port.frequency(1000000);  // Clock frequency is 1MHz
    CS = 1;    //Chip Select idles high  (off i think)

    while (1) {
        switch_word = 0xAA;    //set up word to be transmitted (header?)
        CS = 0;                //select slave device
        ser_port.write(switch_word);  //send switch_word
        CS = 1;
        thread_sleep_for (500);
        switch_word = 0x55;     //set up a word to be transmitted
        CS = 0;
        ser_port.write(switch_word);   //send switch_word
        CS = 1;
        thread_sleep_for (500);

    }
}
*/