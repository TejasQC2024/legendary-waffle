// You have to include a library to control the servo becuase the library is not pre included in the program
#include <Servo.h>

// We give the servo library a name for easy use. like the pandas or numpy library
// in python being named pd or np for ease of use. 
Servo myservo;

// This assigns pins on the arudino to the trig and echo pins from the ultrasonic
// The trig and echo send and recieve the sound wave respectively.
const unsigned int TRIG_PIN=13;
const unsigned int ECHO_PIN=12;

// Sets the pin that the potentiometer sends data to A0 (analog 0).
const int potentiometerPin = A0;

// This is the transmission rate for the information.
const unsigned int BAUD_RATE=9600;

// This initializes the starting postion of the servo to 0 (0 degrees).
int pos = 0;

// The setup for the pins is as follows
void setup() {
  pinMode(TRIG_PIN, OUTPUT); // This is output because the TRIG pin sends the sound wave out.
  pinMode(ECHO_PIN, INPUT); // This is input becuase the ECHO pin recieves the sound wave.
  Serial.begin(BAUD_RATE);
  myservo.attach(2); // This initializes a pin for the servo motor, which is pin 1 in this case.
  myservo.write(pos); // This moves the servo to the position assigned. Which is 0 in this case.

}

// This is the loop that the arduino runs forever.
void loop()  {

  // Reads the analog value from the potentiometer
  int sensorValue = analogRead(potentiometerPin);

  // Prints the value out (this is useful to determine any issues)
  Serial.print("Analog: ");
  Serial.println(sensorValue);
  

 
  // The potentiometer is only considered open if the analog value is less than 300.
  if (sensorValue < 300){
     // The following set of code sends out the sound wave in a little burst.
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN,  HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);


     // This measures the duration between the pulse sent and the pulse recieved. It is measured in microseconds.
    const unsigned long duration= pulseIn(ECHO_PIN, HIGH);

    // The distance is calculated using the d = vt formula and the velocity is converted from m/s into cm/microsecond.
    int distance = duration * 0.0343 / 2;

    // This prints out the distance that the object is from the ultrasonic sensor in cm
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // If there is an object within 10cm of the sensor it will cause the servo to move 90 degrees clockwise
    // hence the door is open.
    if (distance < 10){
    pos = 90; // Feel free to change this value to anything you want, remember the max range of the servo is 180 degrees.
    myservo.write(pos);             
  
    }
  }

  // This is the condition for is the potentiometer is closed, the servo will return to the original position
  // if the analog value is greater than 600.
  if (sensorValue > 600){
    pos = 0;
    myservo.write(pos);
  }
}  
