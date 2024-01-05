int buzzerPin1 = 6;
int buzzerPin2 = 7;
int buzzerPin3 = 8;

void setup() {
  pinMode(buzzerPin1, OUTPUT);
  pinMode(buzzerPin2, OUTPUT);
  pinMode(buzzerPin3, OUTPUT);
}

void loop() {
  // play a note on pin 6 for 200 ms:
  tone(buzzerPin1, 440, 200);
  delay(200);
  noTone(buzzerPin1);

  // play a note on pin 7 for 500 ms:
  tone(buzzerPin2, 494, 500);
  delay(500);
  // turn off tone function for pin 7:
  noTone(buzzerPin2);

  // play a note on pin 8 for 300 ms:
  tone(buzzerPin3, 523, 300);
  delay(300);
  // turn off tone function for pin 8:
  noTone(buzzerPin3);
}
