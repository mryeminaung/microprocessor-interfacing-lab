void setup()
{
  pinMode(10, OUTPUT);
}

void loop()
{
  float x = analogRead(A0); // return value 0 - 1023

  analogWrite(10, x / 4); // analog value 0 - 255

  delay(50);

}
