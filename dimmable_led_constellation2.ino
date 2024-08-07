void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(30);
  for (int i = 10; i < 256; i = i + 2){
    analogWrite(3, i); 
    analogWrite(5, i);
    analogWrite(6, i);
    analogWrite(9, i);
    analogWrite(10, i);
    analogWrite(11, i);
    delay(30);
    if (i==255){
      for(int i = 255; i >= 10; i -= 2){
            analogWrite(3, i); 
            analogWrite(5, i);
            analogWrite(6, i);
            analogWrite(9, i);
            analogWrite(10, i);
            analogWrite(11, i);
            delay(30);
      }
    }
  }
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}