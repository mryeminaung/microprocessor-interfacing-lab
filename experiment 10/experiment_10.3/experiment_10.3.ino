int leds[] = {2, 3, 4, 5, 6};
int threshold = 100;

void setup()
{
  for (int led = 0; led < 5; led++) {
    pinMode(leds[led], OUTPUT);
  }
}

void loop()
{
  int ldrValue = analogRead(A0);
  
  if (ldrValue < threshold) {
    for (int led = 0; led < 5; led++) {
      digitalWrite(leds[led], HIGH);
    }
  } else {
    for (int led = 0; led < 5; led++) {
      digitalWrite(leds[led], LOW);
    }
  }
}
