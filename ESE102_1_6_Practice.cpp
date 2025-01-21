// Attempt to hardcode an 'A' using just binary commands

/*
#include "mbed.h"

//Define Pins
DigitalOut CS(D10);
SPI ser_port(D11, D12, D13);

int main() {
    
    //------Initialization------//
    thread_sleep_for(40);  // Wait 40ms for power-on stabilization

    //Set 8bit mode
     CS = 0; ser_port.write(0b00110000); CS = 1; wait_us(37);   // Set 8bit mode  CGRAM & DDRAM addresses
     CS = 0; ser_port.write(0b00110000); CS = 1; wait_us(37);   // Send 3 time just in case
     CS = 0; ser_port.write(0b00110000); CS = 1; wait_us(37);
     //Set 4bit mode
     CS = 0; ser_port.write(0b00100000); CS = 1; wait_us(37);
     CS = 0; ser_port.write(0b00100000); CS = 1; wait_us(37);
     //Function Set: 4_bit mode, 2-line display, 5x8 character font
     CS = 0; ser_port.write(0b00101000); CS = 1; wait_us(37);
     // Display On, cursor off, blink off
     CS = 0; ser_port.write(0b00001100); CS = 1; wait_us(37);
     // Clear Display
     CS = 0; ser_port.write(0b00000001); CS = 1; wait_us(1520);
     // Entry Mode Set: Increment Cursor Not Display (row 3)
     CS = 0; ser_port.write(0b00000110); CS = 1; wait_us(37);
     
     
     // Clear Display
     CS = 0; ser_port.write(0b00000001); CS = 1; wait_us(1520);
     
     //-----Function-----//   (Write an 'A')
     //Send left half of 'A'
     CS = 0; ser_port.write(0b01001100); CS = 1; wait_us(1);
     //Strobe ENABLE bit back low to activate the change
     CS = 0; ser_port.write(0b01000100); CS = 1; wait_us(37);
     // Now the Lower 4 bits of 'A'
     CS = 0; ser_port.write(0b00011100); CS = 1; wait_us(1);
     // Strobe Enable bit low
     CS = 0; ser_port.write(0b00010100); CS = 1; wait_us(37);
}
*/