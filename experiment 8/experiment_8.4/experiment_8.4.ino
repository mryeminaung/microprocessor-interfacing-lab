int buzzerPin = 9;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  tone(buzzerPin, 500);
  delay(300);

  noTone(buzzerPin);
  delay(200);
}
