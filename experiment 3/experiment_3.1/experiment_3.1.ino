void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void loop() {

  int sw1 = digitalRead(2);

  int sw2 = digitalRead(3);

  int sw3 = digitalRead(4);

  if (sw1 == 1 && sw2 == 0 && sw3 == 0)
  { 
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
  }
  else if (sw1 == 0 && sw2 == 1 && sw3 == 0)
  { 
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
  }
  else if (sw1 == 0 && sw2 == 0 && sw3 == 1)
  { 
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
  else 
  { 
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
  }

  delay(100); // for stability

}
