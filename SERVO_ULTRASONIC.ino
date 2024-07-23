// You have to include a library to control the servo becuase the library is not pre included in the program
#include <Servo.h>

// We give the servo library a name for easy use. like the pandas or numpy library
// in python being named pd or np for ease of use. 
Servo myservo;

// This assigns pins on the arudino to the trig and echo pins from the ultrasonic
// The trig and echo send and recieve the sound wave respectively.
const unsigned int TRIG_PIN=13;
const unsigned int ECHO_PIN=12;

// The setup for the pins is as follows
void setup() {
  pinMode(TRIG_PIN, OUTPUT); // This is output because the TRIG pin sends the sound wave out.
  pinMode(ECHO_PIN, INPUT); // This is input becuase the ECHO pin recieves the sound wave.
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  myservo.attach(2); // This initializes a pin for the servo motor, which is pin 2 in this case.
  myservo.write(0); // This moves the servo to the position assigned. Which is 0 in this case.
}

// This is the loop that the arduino runs forever.
void loop()  {

  digitalWrite(11, HIGH);
  
  // The potentiometer is only considered open if the analog value is less than 300.

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

    if (distance > 10){
      distance  = 8;
    }

    if (distance < 4){
      pos = 90; // Feel free to change this value to anything you want, remember the max range of the servo is 180 degrees.
      myservo.write(pos);
      delay(100);
    }
    else{
      myservo.write(0); // returns the servo back to the original position
      delay(100);
    } 
}  
