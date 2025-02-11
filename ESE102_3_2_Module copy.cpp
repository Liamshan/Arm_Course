/*
// Temperature sensing unit, with the addition of a potentiometer dimming LED
#include "mbed.h"

#define ENABLE 0X08         // Will be IRed in the data value to strobe E bit
#define COMMAND_MODE 0x00   // used to clear RS line to 0, for command transfer (not the same as cs)
#define DATA_MODE 0x04      // used to set RS line to 1 for data transfer

// Define Digital Outputs & SPI port
DigitalOut led(LED1);        //Nucleo LED
DigitalOut CS(D10);          //SPI Chip Select
SPI ser_port(D11, D12, D13); //Initialize SPI, using default settings
//LED & Pot for dimming
AnalogIn pot1(A0);
PwmOut led2(D3);

//Function Prototypes
void clr_lcd(void);
void init_lcd(void);
void print_lcd(const char *string);
void shift_out(int data);
void write_cmd(int cmd);
void write_data(char c);
void write_4bit(int data);

// Temp sensor variables
I2C temp_sensor(I2C_SDA, I2C_SCL);  //Configure I2C interface
BufferedSerial pc(USBTX, USBRX, 9600);
const int temp_addr = 0x90;    //I2C address of temperature sensor DS1631
char commands[] = {0x51, 0xAA};     // Initiates temperature conversions, Reads the last converted temp value from the 2-byte temp register (16 bit)
char read_temp[2];              //Empty array to hold the 16bit temp value
char LCD_result[9];             //hilds result to be displayed on LCD;



//-------------- Threads ------------------//
Thread thread1;    //Blink an LED
void led1_thread(void const *args) {
    led = 0;
    while(true) {
        led = !led;
        thread_sleep_for (500);
    }
}

Thread thread2;   //Display a counter on the LCD
void count_thread(void const *args) {
    char k = 0;
    while(1) {
        write_cmd(0xc0);    //set cursor to start of second line
        wait_us(40);
        print_lcd("Count is ");
        write_data(k|0x30); //)OR in 0x30 to produce the ASCII code for k ????
        k++;
        if (k > 9) k = 0;
        thread_sleep_for (1000);
    }
}

Mutex lcd_mutex;   //Declare mutex object
Thread thread3;
//Read temp and display on LCD
void temp_thread(void const *args) {
    while(1) {
        lcd_mutex.lock();   //dedicate this thread until done
        //Write 0xAA to sensor to read the last converted temp
        temp_sensor.write(temp_addr, &commands[1], 1, false);
        //Read temp into the read_temp array
        temp_sensor.read(temp_addr, read_temp, 2);
        //Convert temp to Celsius. Shift MS byte right by 8 bits, or in LS byte,
        //then divide all by 256, with float result.
        float temp = (float((read_temp[0] << 8) | read_temp[1])/256);
        //convert float to character string
        sprintf(LCD_result, "%d.%d", int(temp), int((temp-int(temp))*10));
        write_cmd(0x80);   //set cursor to start of first line
        wait_us(40);
        for (char i = 0; i < 4; i++) {  //write 5 characters from string
            write_data(LCD_result[i]);
        }          //end of for()
        print_lcd(" degrees C");

        //Write 0x51 to the DS1631 (address 0x90) to start next temp conversion
        temp_sensor.write(temp_addr, &commands[0], 1, false);
        lcd_mutex.unlock();   //realease this thread
        thread_sleep_for(1000);
    }
}

Thread thread4;
void dim_led2(void const *args) {
    while(1) {
        led2 = pot1;
    }
}




//---------------MAIN Function----------------//
int main() {
    init_lcd();  //Initialize the LCD display
    clr_lcd();   //CLear the LCd
    thread1.start(callback(led1_thread, &led));       //  thread.start(callback(task, argument));
    thread2.start(callback(count_thread, &ser_port));
    thread3.start(callback(temp_thread, &temp_sensor));
    thread4.start(callback(dim_led2, &pot1));

    while(true) {           //Wait for timer interrupt
        __WFI();
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



*/