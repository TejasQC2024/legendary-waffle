// Include libraries to control the servo and to use the button aspect of the joystick
#include <Servo.h>
#include <ezButton.h>

// Define the pins the joystick is connected too
#define X_PIN A0
#define Y_PIN A1
#define BUTTON_PIN 2

// Enable the joystick button function at the digital pin
ezButton button(BUTTON_PIN);

// declare variables for the different pins
const int servo1pin = 10;
const int servo2pin = 7;
const int servo3pin = 4;

// create servo objects
Servo servo1;
Servo servo2;
Servo servo3;

// initialize variables for button code and for servo angle (angle)
int x_Value;
int y_Value;
int button_state;
int angle;

void setup() // code that only runs once
{
  // Debouncer to ensure proper button inputs
  button.setDebounceTime(50);

  // attach servo objects to pins
  servo1.attach(servo1pin);
  servo2.attach(servo2pin);
  servo3.attach(servo3pin);

  // Move the servos to 90 degrees
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  
  // Initalize serial communication speed for debugging
  Serial.begin(9600);
}

void loop()
{
  // Takes in the input from the button
  button.loop();

  // Reads the X and Y values from the joysticks and determines weather the button is pressed or not.
  x_Value = analogRead(X_PIN);
  y_Value = analogRead(Y_PIN);
  button_state = button.getState();
  
  // Prints the X and Y analog value for the joystick
  Serial.print(x_Value);
  Serial.print("  ");
  Serial.println(y_Value);

  // if the button is pressed down
  if(button.isPressed()){
    //code to move servo3 to closed position
    Serial.println("Pressed");
    servo1.write(0);
    delay(50);
  }
  // if the button is released
  if(button.isReleased()){
    //code to move servo3 to released position
    Serial.println("Released");
    servo1.write(90);
    delay(50);
  }
  // -------------------------------------------------------------
  // Line of code for x direction movement
  if (x_Value < 450)
  { // goes left
    Serial.println("Left");
    angle = (x_Value / 483) * (90); // determines angle for the servo 
    servo2.write(angle); // moves the servo to the specific angle
    delay(50);
  }
  if (x_Value > 500)
  { // goes right
  Serial.println("Right");
  angle = 90 + ((x_Value / 483) * (90));
    servo2.write(angle);
    delay(50);
  }
  if(x_Value == 482)
  {// if the joystick is in the middle it returns to the original position
    servo2.write(90);
    delay(50);
  }
  // -------------------------------------------------------------
  // For y direction movement
  if(y_Value < 510)
  { // goes up
    Serial.println("Up");
    angle = (y_Value / 516) * (90);
    servo3.write(angle);
    delay(50);
  }
  if(y_Value > 520)
  { // goes down
    Serial.println("Down");
    angle = 90 + (y_Value/520 * 35);
    servo3.write(angle);
    delay(50);
  }
  if(y_Value > 510 && y_Value < 520)
  {// if it is in the middle it returns to the original position
    servo3.write(90);
    delay(50);
  }
  delay(100);
}