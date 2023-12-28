void setup()
{ 
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    String num = Serial.readString();
    int x = num.toInt(); // toInt method is used to convert input string to int
   
    if (0 <= x && x <= 100) {
      if (x <= 50)
      {
        digitalWrite(13, HIGH);
      }
      else
      {
        digitalWrite(13, LOW);
      }
    }
  }
}
