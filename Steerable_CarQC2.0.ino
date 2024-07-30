// This is the library needed for the remote control
// REMEMBER TO DOWNLOAD VERSION 2.6 of the IR library
#include <IRremote.h>

// This is assigning ports on the arduino to various pins that may be attached
int in1=2; // for in1 on the motor shield
int in2=4; // for in2
int in3=7; // for in3 
int in4=8; // for in4
const int RemotePin=13; // assigns a pin to recieve the remote data in this case pin 13

// This prepares the arduino to recieve the data from the remote
IRrecv irrecv(RemotePin);
// This is to decode the data that the arduino recieves from the remote it renames it to results
// so that it is a little easier to code within the script.
decode_results results;

// Loop for the setup (prepares the arduino to recieve the information)
void setup() {
  // Initializes serial communication at 9600 BAUD
  Serial.begin(9600);
  // Enables recieving the IR data and begins to recieve data
  irrecv.enableIRIn();
  // This connects the motor control ports on the motor shield
  // to the arduino and initializes them as outputs so you can send signals to them
  pinMode(in1, OUTPUT); // This is clockwise rotation for motor A
  pinMode(in2, OUTPUT); // This is clockwise rotation for motor B
  pinMode(in3, OUTPUT); // This is counter clockwise rotation for motor A
  pinMode(in4, OUTPUT); // This is counter clockwise rotation for motor B 
}
// This is the main loop that the arduino will be running through.
void loop() {
    // This recieves the data from the remote, decodes it and returns it to the user.
    if(irrecv.decode(&results)){
      // Print out the value recieved from the remote in HEXADECIMAL and then DECIMAL(normal number system).
      Serial.println(results.value, HEX);
      // Delay for the signal recieved (this helps with the signals not getting distorted).
      delay(300);
    
		if (results.value == 0xFF629D)// If Press UP Button calls the forward function
        { 
          Forward();
          Serial.println("Forward");
        }
        else if (results.value==0xFFA857)//If Press Down Button calls the backward function
        { 
          Backward();
          Serial.println("Backward");
        }
         else if (results.value==0xFF22DD)//If Press Left Button calls the left function
        { 
          Left();
          Serial.println("Left");
        }
        else if (results.value==0xFFC23D)//If Press Right Button calls the right function
        { 
          Right();
          Serial.println("Right");
        }
        else if (results.value==0xFF02FD)//If Stop Button is pressed calls the stop function
        { 
        Stop();
        Serial.print("Stop");
      }
      // This is so that arduino resumes the acceptance for the data from the remote.
      irrecv.resume();
    }
}
   
// Function for the backwards movement, it moves motors A and B clockwise (makes it turn backwards)
void Backward()
  {
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  }

// Function for the forwards movement, it moves motors A and B counter clockwise (makes it go forwards)
 void Forward()
  {
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  }
 // Function for stopping. It sets all the motors to LOW, which turns them off.
 void Stop()
  {
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  }
  // Function for turning left, It sets only the motors on the right side to high and has them turn counter clockwise.
  int Left()
    {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    }
  // Function for turning right, It sets only the motors on the left side to high and has them turn clockwise.
  int Right()
    {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    }