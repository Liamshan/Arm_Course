// Successfully moving an character across the screen.

/*
#include "mbed.h"

#define ENABLE 0x08      // Will be ORed in the data value to strope E bit
#define COMMAND_MODE 0x00  //Used to clear RS line to 0, for command transfer
#define DATA_MODE 0x04   // Used to set the RS data line to 1 to allow data transfer


//Define Pins
DigitalOut CS(D10);
SPI ser_port(D11, D12, D13);



//Function Prototypes
void init_lcd(void);
void clr_lcd(void);
void shift_out(int data);
void write_cmd(int cmd);
void write_data(char c);
void write_4bit(int data, int mode);
void move_character_animation(void);

//---------------------------------------------//
int main() {
    init_lcd();   //Initialize the LCD
    clr_lcd();    //Clear the LCD
    move_character_animation();
}

void init_lcd(void) {
    thread_sleep_for(40);  // Wait 40ms for power-on stabilization
    // Send the initialization commands for 8-bit mode and transition to 4-bit mode
    shift_out(0x30);      // 0x30 is the command to set to 8-bit mode
    wait_us(37);
    write_cmd(0x20);      // Set to 4 bit mode
    wait_us(37);
    write_cmd(0x20);     // Set to 4 bit mode again for some reason
    wait_us(37);
    write_cmd(0x0C);     //Display on, cursor off, blink off
    wait_us(37);
    write_cmd(0x01);     //Clear Display:
    wait_us(1520);
    write_cmd(0x06);     //Entry Mode Set: Increment cursor position (as opposed to display shifting)
    wait_us(37);
    write_cmd(0x28);     // Function set: 4-bit mode, 2-line display, 5x8 character font
}

void clr_lcd(void) {
    write_cmd(0x01);    //Clear display
    wait_us(1520);
}

void shift_out(int data) {
    CS = 0;    //Set controller to active
    ser_port.write(data);  //write watever message is entered into the function
    CS = 1;    // Chip Select reset
}

void write_cmd(int cmd) {
    write_4bit(cmd, COMMAND_MODE);
}

void write_data(char c) {
    write_4bit(c, DATA_MODE);
}

void write_4bit(int data, int mode) {
    int hi_n = (data & 0xF0);        // this uses & to isolate the left 4 bits by anding "data" with 1111 0000
    int lo_n = ((data << 4) & 0xF0);  // this moves the right bits to the left and does the same
    shift_out(hi_n | ENABLE | mode);  // this sends all the values in 1 message with an or operator
    wait_us(1);
    shift_out(hi_n & ~ENABLE);        // Enable needs to be strobed hi then lo before the LCD reads the hi_n bits. 
    //Now for the lo_n
    shift_out(lo_n | ENABLE | mode);   
    wait_us(1);
    shift_out(lo_n & ~ENABLE);        // Same thing with lo_n
}

void move_character_animation(void) {
    //write_cmd(0x80);     // Set cursor to first position (line 1, column 1)
    //write_data('A');      //   Display the character 'A' at that position
        // First Row
    for (int i = 0; i < 20; i++) {
        clr_lcd();              // Clear the LCD
        write_cmd(0x80 + i);    // Write in next position
        write_data('A');
        thread_sleep_for(500);
    }    // Second Row
    for (int j = 0; j < 20; j++) {
        clr_lcd();
        write_cmd(0xC0 + j);  // Start at second row (0x80 + 0x40) cuz need 0x80 (msb) value to always be 1
        write_data('A');
        thread_sleep_for(500);
    }   // Third Row
    for (int i = 20; i < 40; i++) {
        clr_lcd();              // Clear the LCD
        write_cmd(0x80 + i);    // Write in next position
        write_data('A');
        thread_sleep_for(500);
    }    // Fourth Row
    for (int j = 20; j < 40; j++) {
        clr_lcd();
        write_cmd(0xC0 + j);  // Start at second row (0x80 + 0x40) cuz need 0x80 (msb) value to always be 1
        write_data('A');
        thread_sleep_for(500);
    }
    clr_lcd();
}
*/