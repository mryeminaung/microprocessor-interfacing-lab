void setup()
{ 
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char x = Serial.read();
    Serial.println(x);

    if (x == '1')
    {
      digitalWrite(13, HIGH);
    }
    else if(x == '0')
    {
      digitalWrite(13, LOW);
    }
  }
  delay(1000);
}
