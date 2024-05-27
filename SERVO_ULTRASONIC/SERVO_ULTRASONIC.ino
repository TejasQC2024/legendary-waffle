// You have to include a library to control the servo becuase the library is not pre included in the program
#include <Servo.h>

// We give the servo library a name for easy use. like the pandas or numpy library
// in python being named pd or np for ease of use. 
Servo myservo;

// This assigns pins on the arudino to the trig and echo pins from the ultrasonic
// The trig and echo send and recieve the sound wave respectively.
const unsigned int TRIG_PIN=13;
const unsigned int ECHO_PIN=12;
//int led1 = 6;
//int led2 = 7;

// This is the transmission rate for the information.
const unsigned int BAUD_RATE=9600;
//This assigns a pin on the arduino for the button.
const int buttonPin = 5;

// This initializes the starting postion of the servo to 0 (0 degrees).
int pos = 0;

// The setup for the pins is as follows
void setup() {
  pinMode(TRIG_PIN, OUTPUT); // This is output because the TRIG pin sends the sound wave out.
  pinMode(ECHO_PIN, INPUT); // This is input becuase the ECHO pin recieves the sound wave.
  Serial.begin(BAUD_RATE);
  myservo.attach(2); // This initializes a pin for the servo motor, which is pin 1 in this case.
  myservo.write(pos); // This moves the servo to the position assigned. Which is 0 in this case.

  // FOR LED
  //pinMode(led1, OUTPUT);
  //pinMode(led2, OUTPUT);
}

// This is the loop that the arduino runs forever.
void loop()  {

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

  // This initializes the state of the button to 0 or OFF.
  int buttonState = 0;

  // This reads the state of the button.
  buttonState = digitalRead(buttonPin);

  // This prints out the distance of an object from the sensor. It is a good way to check if 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");



  // The servo only rotates if the sensor detects an object (your hand) within 10cm of the sensor.
  if (distance < 10){
    pos = 90; // Feel free to change this value to anything you want, remember the max range of the servo is 180 degrees.
    myservo.write(pos);             
    //digitalWrite(led1, HIGH); 
    //digitalWrite(led2, LOW);
  }


  // This is code to return the servo to its initial position (0), When the button is pressed. 
  if(buttonState == HIGH){
    pos = 0;
    myservo.write(pos);
    //digitalWrite(led2, HIGH);
    //delay(50);
    //digitalWrite(led1, LOW);
  }
  
}