//Tell the user if the temperature is too hot or too cold

/*
// Reads temp from DS1631 and displays on PC Terminal

#include "mbed.h"

#define ENABLE 0X08         // Will be IRed in the data value to strobe E bit
#define COMMAND_MODE 0x00   // used to clear RS line to 0, for command transfer (not the same as cs)
#define DATA_MODE 0x04      // used to set RS line to 1 for data transfer

I2C temp_sensor(I2C_SDA, I2C_SCL); // Configure I2C interface
BufferedSerial pc(USBTX, USBRX, 9600);

DigitalOut CS(D10);
SPI ser_port(D11, D12, D13);     //Initialise SPI, using default settings.

const int temp_addr = 0x90;  //I2C address of temperature sensor DS1631
char commands[] = {0x51, 0xAA};
char read_temp[2];
char LCD_result[9];         //holds result to be displayed on LCD

//Function Prototypes
void init_lcd(void);
void clr_lcd(void);
void print_lcd(const char *string);
void shift_out(int data);
void write_cmd(int cmd);
void write_data(char c);
void write_4bit(int data, int mode);
void move_character_animation(void);
void temp_result(float &temp);

int main() {
    init_lcd();    //Initialize the LCD
    clr_lcd();     //Clear the LCD
    print_lcd("Temperature is");

    while(1) {
        //Write 0x51 to 0x90 to start temperature conversion
        temp_sensor.write(temp_addr, &commands[0], 1, false);   ///wtf?
        thread_sleep_for (500);      //wait for the conversion to complete
        //Write 0xAA to ox90 to read the last converted temperature
        temp_sensor.write(temp_addr, &commands[1], 1, false);
        //Read the temperature into the ready_temp array.
        temp_sensor.read(temp_addr, read_temp, 2);
        //Convert temperature to Calcuis
        float temp = (float((read_temp[0] << 8) | read_temp[1]) / 256);
        //Print temperature to the serial monitor
        printf("Temp = %d.%d\r\n", int(temp), int((temp-int(temp))*10));

        //convert float value in temp to character string in LCd_result
        sprintf(LCD_result, "%d.%d", int(temp), int((temp-int(temp))*10)); //store %d.%d in LCD_result
        write_cmd(0xc0);              //Set cursor to start of second ine
        wait_us(40);
        for (char i = 0; i < 4; i++) {    //write 5 characters from string to LCD
            write_data(LCD_result[i]);
        }
        print_lcd(" degree C");   //add units

        //Now Write If it's too hot or too cold. 
        write_cmd(0x94);  //Set cursor to start of third line
        wait_us(40);
        print_lcd("It is: ");
        temp_result(temp);   //print "too hot" or "too cold"

    }
}


//-------------other functions---------------//
void init_lcd(void) {   //follow designated procedure in data sheet
    thread_sleep_for (40);
    shift_out(0x30);    //function set 8-bit
    wait_us(37);
    write_cmd(0x20);    //function set
    wait_us(37);
    write_cmd(0x20);    //function set
    wait_us(37);
    write_cmd(0x0C);    //display ON/OFF
    wait_us(37);
    write_cmd(0x01);    //display clear
    wait_us(1520);
    write_cmd(0x06);    //entry-mode set
    wait_us(37);
    write_cmd(0x28);    //function set
    wait_us(37);
}

void write_4bit(int data, int mode) {   //mode is RS line, ie 0 for cmd, 1 for data
    int hi_n;
    int lo_n;
    hi_n = (data & 0xF0);               //from the two 4-bit nubbles that will be sent
    lo_n = ((data << 4) &0xF0);
    shift_out(hi_n | ENABLE | mode);    //send each word twice, strobing the Enable line
    wait_us(1);
    shift_out(hi_n & ~ENABLE);
    shift_out(lo_n | ENABLE | mode);
    wait_us(1);
    shift_out(lo_n & ~ENABLE);
}
void shift_out(int data) {  //Invokes SPI  (so it latches the message to send)
    CS = 0;
    ser_port.write(data);
    CS = 1;
}

void write_cmd(int cmd) {
    write_4bit(cmd, COMMAND_MODE);
}

void write_data(char c) {
    write_4bit(c, DATA_MODE);   //1 for data mode
}

void clr_lcd(void) {
    write_cmd(0x01);    //display clear
    wait_us(1520);
}

void print_lcd(const char *string) {
    while(*string){
        write_data(*string++);// Send character to LCD and then move to the next char in the string
        wait_us(40);
    }
}

void temp_result(float &temp) {
    if (temp > 21.9) {
        print_lcd("too hot ");
    } else {
        print_lcd("too cold");
    }
}
*/