/*
Using temp sensor. Next, 
1. Finish understanding each line of the code
2. Complete the code on the LCD Display
3. Try to write your own code for a theromostat
*/

/*
// Reads temp from DS1631 and displays on PC Terminal

#include "mbed.h"

I2C temp_sensor(I2C_SDA, I2C_SCL); // Configure I2C interface
BufferedSerial pc(USBTX, USBRX, 9600);

const int temp_addr = 0x90;  //I2C address of temperature sensor DS1631
char commands[] = {0x51, 0xAA};
char read_temp[2];

int main() {

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
    }
}
*/