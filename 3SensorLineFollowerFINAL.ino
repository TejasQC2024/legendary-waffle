// #define creates global variables, these should stay the same throughout the code
#define RS 12    // Right sensor
#define MS 11    // Middle Sensor
#define LS 13     // Left sensor

#define LM1 9       // left motor forward
#define LM2 6       // left motor backward
#define RM1 5       // right motor forward
#define RM2 3       // right motor backward

// Speed settings
#define DEFAULT_SPEED 200 // Default speed for forward movement
#define TURN_SPEED 150   // Speed for turning

int dir = 0; //This sets which way the bot should be moving. 0 means forwards, 1 means turn right, 2 means turn left

void setup() {
  delay(100);
  
  Serial.begin(9600); //This sets up the Serial monitor. The number is called the Baud Rate, it is the rate information is transmitted to the monitor in bits/second
  
  //The pinMode function allows you to associate a single Arduino pin with a variable and set whether that pin reads or transmits information
  pinMode(MS, INPUT); //These three lines set the sensor pins to receive inputs
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);

  pinMode(RM1, OUTPUT); //These four lines set the motor pins to transmit information
  pinMode(RM2, OUTPUT);
  pinMode(LM1, OUTPUT); 
  pinMode(LM2, OUTPUT);
}

void forward() { // This is a function that can be called whenever the bot needs to move forward

    Serial.print(" Move Forward "); 
    //The analogWrite function allows the user to set a PWM pin to be on for a specific % of time allowing for changes in motor speed
    analogWrite(RM2, DEFAULT_SPEED); 
    analogWrite(RM1, 0);
    analogWrite(LM1, DEFAULT_SPEED);
    analogWrite(LM2, 0);
}

void right() { // This is a function that can be called whenever the bot needs to turn right

    Serial.println("Turn Right");
    analogWrite(RM1, 0);
    analogWrite(RM2, TURN_SPEED);
    analogWrite(LM2, TURN_SPEED);
    analogWrite(LM1, 0);
}

void left() { // This is a function that can be called whenever the bot needs to turn left

    Serial.println("Turn Left");
    analogWrite(RM1, TURN_SPEED);
    analogWrite(RM2, 0);
    analogWrite(LM2, 0);
    analogWrite(LM1, TURN_SPEED);
}


void loop() {

  //These next three if statements are tests to check if the IR sensors work properly
  //When the sensor is over the tape a message saying HIGH should appear in the serial monitor

  //The digitalRead function reads whether a pin is experiencing a HIGH or LOW signal
  //If the IR sensor sees white it sends LOW and if it sees black it sends HIGH
  if (digitalRead(MS) == HIGH){ 
    Serial.print("MS HIGH ");
  }

  if (digitalRead(RS) == HIGH){
    Serial.print("RS HIGH ");
  }

  if (digitalRead(LS) == HIGH){
    Serial.print("LS HIGH ");
  }

  Serial.println(dir); //This reads to the serial monitor how the bot thinks it is moving

    //This reads that as long as the middle sensor sees black it will continue moving forward
    if (digitalRead(MS) == HIGH) { 
      forward();
      }
    
    //This reads that if the middle sensor does not see black it will continue moving forward until a side sensor sees black
    //Once the side sensor sees black it will change the direction value and make the robot turn until the middle sensor sees black again
    

    if (digitalRead(RS) == HIGH) { 
      dir = 1; 
    }
    
    else if (digitalRead(LS) == HIGH){
      dir = 2;
    }
    
    if (digitalRead(MS) == LOW) {

      if (dir == 1) { //if middle does not see black and most recently right did it will turn right
      right();
      }

      else if (dir == 2) { //if middle does not see black and most recently left did it will turn left
      left();
      } 
    }
  delay(50); // delay lets the sensors and motors have a small amount of time to reset before running again
}