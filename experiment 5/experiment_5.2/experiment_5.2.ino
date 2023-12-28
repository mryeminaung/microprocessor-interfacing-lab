void setup()
{
  Serial.begin(9600);
}
void loop()
{
  float x = analogRead(A0);

  Serial.println((x / 1023) * 5.0);

  delay(1000);
}
