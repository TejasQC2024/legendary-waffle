// Define analog input
#define sensorPin A0
// Define the pin the speaker will be connected to 
int speakerPin = 2;
int ledPin = 13;

void setup() {
  // Setup Serial Monitor
  Serial.begin(9600);
  // Allows us to send signals to the speaker
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the Analog Input
  int soilMoisture = analogRead(sensorPin);
  // Print the moisture value to the serial monitor the higher the number the lower the moisture
  int soilmoisturepercent = abs(map(soilMoisture, 0, 679, 0, 100));
  Serial.print("Analog Value: ");
  Serial.println(soilMoisture);
  Serial.print("soilmoisturepercent: ");
  Serial.println(soilmoisturepercent);
  // If the moisture is too low then play a beep that continues until the moisture level is correct
  if(soilmoisturepercent < 17){
    tone(speakerPin, 50, 400);
    delay(2000);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  // Wait for 1 second before the next reading
  delay(1000);
}
