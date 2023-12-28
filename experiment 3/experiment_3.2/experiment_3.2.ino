void setup()
{
  pinMode(9, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
}

void loop() 
{
  int sw1 = digitalRead(2);
  int sw2 = digitalRead(3);
  int sw3 = digitalRead(4);
  int sw4 = digitalRead(5);

  int decimalValue = (8 * sw4) + (4 * sw3) + (2 * sw2) + (1 * sw1);

  if(decimalValue >= 9) {
    digitalWrite(9, HIGH);
  }else {
    digitalWrite(9, LOW); 
  }
  
  delay(100); // for stability

}
