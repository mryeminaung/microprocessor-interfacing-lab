void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int sig1 = analogRead(A0);
  int sig2 = analogRead(A1);

  Serial.print("Signal 1 : ");
  Serial.println(sig1);

  Serial.print("Signal 2 : ");
  Serial.println(sig2);

  if (sig1 > sig2) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  delay(1000);
}
