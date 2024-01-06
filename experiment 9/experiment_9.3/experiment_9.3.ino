int buzzerPin = 9;
int threashold = 10;

int notes[] = { 500, 1000, 1500 };

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int sw1 = analogRead(A0);
  int sw2 = analogRead(A1);
  int sw3 = analogRead(A2);

  if (sw1 >= threashold)
    tone(buzzerPin, notes[0]);
  else if (sw2 >= threashold)
    tone(buzzerPin, notes[1]);
  else if (sw3 >= threashold)
    tone(buzzerPin, notes[2]);
  else noTone(buzzerPin);
}
