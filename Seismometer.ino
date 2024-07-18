// Library for the Accelerometer
#include<Wire.h>

// This initializes the memory address that the MPU6050 will send data to for the I2C protocol
const int MPU_addr=0x68;
// This initializes some variables for the accelerometer
int16_t AcX,AcY; // The variables are for the accelerations in different axis the data is read in binary

// The main setup loop
void setup(){

  // The following lines of code initialize the transmission of the MPU6050 data
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  // The data will be written to this address
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  
  // Sets communication rate between devices to 9600 BAUD
  Serial.begin(9600);

}
void loop(){

// Begin the transmission for the data from the MPU6050
Wire.beginTransmission(MPU_addr);
Wire.write(0x3B);
Wire.endTransmission(false);
Wire.requestFrom(MPU_addr,14,true);

// This reads the specific acceleration data from the Accelerometer
float wireAccX=Wire.read()<<8|Wire.read();
float wireAccY=Wire.read()<<8|Wire.read();

// This is used to convert the data from the accelerometer into 
// a form that is commonly used (Gs)
float xAcc = abs((wireAccX / 16384));
float yAcc = abs((wireAccY / 16384));

float absAcc = sqrt(pow(xAcc, 2) + pow(yAcc, 2));

// The folowing code is used to print values to the serial monitor and plotter
Serial.print("xAcc:");
Serial.print(xAcc);
Serial.print(", ");

Serial.print("yAcc:");
Serial.print(yAcc);
Serial.print(", ");

Serial.print("absAcc:");
Serial.print(absAcc);
Serial.println();
}