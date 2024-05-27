// Initialize variables and pins for 13 LEDS
int led0 = 0;
int led1 = 1;
int led2 = 2;
int led3 = 3;
int led4 = 4;
int led5 = 5;
int led6 = 6;
int led7 = 7;
int led8 = 8;
int led9 = 9;
int led10 = 10;
int led11= 11;
int led12 = 12;


void setup() {

  // Setup for the LEDs as outputs
  pinMode(led0,OUTPUT);
   pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);
   pinMode(led3,OUTPUT);
   pinMode(led4,OUTPUT);
   pinMode(led5,OUTPUT);
   pinMode(led6,OUTPUT);
   pinMode(led7,OUTPUT);
   pinMode(led8,OUTPUT);
   pinMode(led9,OUTPUT);
   pinMode(led10,OUTPUT);
   pinMode(led11,OUTPUT);
   pinMode(led12,OUTPUT);
  
}

//The main loop for your code where the program repeats
void loop() 
{
  // These are functions that are called. Each function is its own led pattern.
  // The first is a demo pattern to get you used to the code
  blink_1();
  // This is a function for the second pattern, feel free to add more functions as you create more patterns
  blink_2();

}

/////////////pattern 1///////////////////////////////////////////////////////////////////////////////////////////////////
void blink_1()
{
  // This is a variable for the delay, which in this case is 80 milliseconds
  int t=80;
  
  // This turns the led at pin 0 on
  // the function digitalWrite has two parameters the LED and 
  // the state. Which is weather the LED is on or off. Below the LED led0 is on because the state is HIGH
  // if the LED were off the state would be LOW.
  digitalWrite(led0, HIGH );
  delay(t);
  digitalWrite(led1,HIGH);
  delay(t);
  digitalWrite(led2,HIGH);
  delay(t);
  digitalWrite(led3,HIGH);
  delay(t);
  digitalWrite(led4,HIGH);
  delay(t);
  digitalWrite(led5,HIGH);
  delay(t);
  digitalWrite(led6, HIGH );
  delay(t);
  digitalWrite(led7,HIGH);
  delay(t);
  digitalWrite(led8,HIGH);
  delay(t);
  digitalWrite(led9,HIGH);
  delay(t);
  digitalWrite(led10,HIGH);
  delay(t);
  digitalWrite(led11,HIGH);
  delay(t);
  digitalWrite(led12,HIGH);
  delay(t);
 
// Code to turn the LEDs off after the pattern has been displayed
digitalWrite(led0, LOW);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);
digitalWrite(led5,LOW);
digitalWrite(led6, LOW);
digitalWrite(led7,LOW);
digitalWrite(led8,LOW);
digitalWrite(led9,LOW);
digitalWrite(led10,LOW);
digitalWrite(led11,LOW);
digitalWrite(led12,LOW);

}

void blink_2()
{
  // This is a variable for the delay, which in this case is 80 milliseconds
  int t=80;
  // This turns the led at pin 0 on
  // the function digitalWrite has two parameters the LED and 
  // the state. Which is weather the LED is on or off. Below the LED led0 is on because the state is HIGH
  // if the LED were off the state would be LOW.
  // To control which LEDs you want to turn on, fill in the blanks below.
  digitalWrite(-----, HIGH );
  delay(t);
  digitalWrite(-----,HIGH);
  delay(t);
  digitalWrite(-----,HIGH);
  delay(t);
  digitalWrite(-----,HIGH);
  delay(t);
  digitalWrite(-----,HIGH);
  delay(t);
  digitalWrite(-----,HIGH);
  delay(t);
  digitalWrite(-----, HIGH );
  delay(t);
  digitalWrite(-----,HIGH);
  delay(t);
  digitalWrite(-----,HIGH);
  delay(t);
  digitalWrite(-----,HIGH);
  delay(t);
  digitalWrite(-----,HIGH);
  delay(t);
  digitalWrite(-----,HIGH);
  delay(t);
  digitalWrite(-----,HIGH);
  delay(t);
 
// Code to turn the LEDs off after the pattern has been displayed
digitalWrite(led0, LOW);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);
digitalWrite(led5,LOW);
digitalWrite(led6, LOW);
digitalWrite(led7,LOW);
digitalWrite(led8,LOW);
digitalWrite(led9,LOW);
digitalWrite(led10,LOW);
digitalWrite(led11,LOW);
digitalWrite(led12,LOW);
}

