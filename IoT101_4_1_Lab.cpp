/*

 #include "mbed.h"
 #include "stm32l475e_iot01_tsensor.h"
 #include "stm32l475e_iot01_hsensor.h"
 #include "stm32l475e_iot01_psensor.h"
 #include "stm32l475e_iot01_magneto.h"
 #include "stm32l475e_iot01_accelero.h"
 #include "stm32l475e_iot01_gyro.h"
 #include <cstdint>
 
 
 static DigitalOut led(LED1);
 static BufferedSerial serial_port(USBTX, USBRX, 9600);
 static LowPowerTicker ledTicker;
 static LowPowerTicker readoutTicker;
 static bool shouldReadSensors;
 
 FileHandle *mbed::mbed_override_console(int fd) {
     return &serial_port;
 }
 
 static void ledTick() {
     led = !led;
 }
 
 static void readoutTick() {
     shouldReadSensors = true;
 }
 
 static void initialiseSensors() {
     BSP_TSENSOR_Init();
     BSP_HSENSOR_Init();
     BSP_PSENSOR_Init();
     BSP_MAGNETO_Init();
     BSP_ACCELERO_Init();
     BSP_GYRO_Init();
 }
 
 static float convertCelsiusToFarenheight(float t) {
     return ((t * 9.) / 5.) + 32.;    //what is the decimal for
 }
 
 static float convertCelsiusToKelvin(float t) {
     return t + 273.15;
 }
 
 static void readSensors() {
     printf("Sensor values:\n");
 
     float temp = BSP_TSENSOR_ReadTemp();
     printf("* Temperature: %f C, %f F, %f K\n", temp, convertCelsiusToFarenheight(temp), convertCelsiusToKelvin(temp));
 
     float hum = BSP_HSENSOR_ReadHumidity();
     printf("* Humidity: %f\n", hum);
 
     float prs = BSP_PSENSOR_ReadPressure();
     printf("* Pressure: %f\n", prs);
 
     int16_t magneto[3];
     BSP_MAGNETO_GetXYZ(magneto);   //ask to clarify this
     printf("* Magneto: %d %d %d\n", magneto[0], magneto[1], magneto[2]);  //why are these doubles not floats (cuz uint?)
 
     float gyro[3];
     BSP_GYRO_GetXYZ(gyro);   //what is (gyro) is it a defined in the getxyz function as the variable you need to populate when getting those values?
     printf("* Gyro: %f %f %f\n", gyro[0], gyro[1], gyro[2]);
 
     int16_t accel[3];
     BSP_ACCELERO_AccGetXYZ(accel);
     printf("* Accelerometer: %d %d %d\n", accel[0], accel[1], accel[2]);
 
 
 }
 
 int main() {
     led = true;
     printf("Hello, world.\n");
 
     initialiseSensors();
 
     ledTicker.attach(&ledTick, 1s);
     readoutTicker.attach(&readoutTick, 3s);
 
     while (true) {
         sleep();
         if (shouldReadSensors) {
             readSensors();
             shouldReadSensors = false;
         }
     }
 
     return 0;
 }

*/