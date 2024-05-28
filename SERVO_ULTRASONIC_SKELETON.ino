// You have to include a library to control the servo because the library is not pre included in the program 

// We give the servo library a name for easy use. like the pandas or numpy library 

// in python being named pd or np for ease of use.  

// This assigns pins on the Arduino to the trig and echo pins from the ultrasonic 

// The trig and echo send and receive the sound wave respectively. 

// Sets the pin that the potentiometer sends data to A0 (analog 0). 


// This is the transmission rate for the information. 


// This initializes the starting position of the servo to 0 (0 degrees). 


// The setup for the pins is as follows 

void setup() { 

   // This is output because the TRIG pin sends the sound wave out. 


   // This is input because the ECHO pin receives the sound wave. 


   // This begins the information transmission 

  Serial.begin(BAUD_RATE); 

// This initializes a pin for the servo motor, which is pin 2 in this case. 

 

// This moves the servo to the position assigned. Which is 0 in this case. 


} 


// This is the loop that the Arduino runs forever. 

void loop()  { 

  // Reads the analog value from the potentiometer 

  // Prints the value out (this is useful to determine any issues) 


  // The potentiometer is only considered open if the analog value is less than 300. 

  if (-------- < -------){ 

    // The following set of code sends out the sound wave in a little burst. 

    // This measures the duration between the pulse sent and the pulse received. It is measured in microseconds. 


    // The distance is calculated using the d = vt formula and the velocity is 	converted from m/s into cm/microsecond then 
    // divide by two because the sound wave travels to the location AND BACK. 
 

    // This prints out the distance that the object is from the ultrasonic sensor 	  in cm 

     


    // If there is an object within 10cm of the sensor it will cause the servo to 	  move 90 degrees clockwise hence the door is open. 

    if (-------- < --------){ 

    } 

  } 

  // This is the condition for is the potentiometer is closed, the servo will return to the original position 

  // if the analog value is greater than 600. 

  if (--------- > --------){ 

    
  } 

}   
