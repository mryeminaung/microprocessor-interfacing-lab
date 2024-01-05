int buzzerPin1 = 6;
int buzzerPin2 = 7;
int buzzerPin3 = 8;

void setup() {
  pinMode(buzzerPin1, OUTPUT);
  pinMode(buzzerPin2, OUTPUT);
  pinMode(buzzerPin3, OUTPUT);
}

void loop() {
  tone(buzzerPin1, 440, 250);
  delay(250);
  noTone(buzzerPin1);

  tone(buzzerPin2, 494, 300);
  delay(300);
  noTone(buzzerPin2);

  tone(buzzerPin3, 523, 400);
  delay(400);
  noTone(buzzerPin3);
}
