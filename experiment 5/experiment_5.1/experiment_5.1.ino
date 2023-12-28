void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int x = analogRead(A0);

  Serial.println(x);

  delay(1000);

}
