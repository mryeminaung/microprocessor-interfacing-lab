int buzzerPin = 7;
int threshold = 10;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}
void loop() {
  int sw1 = analogRead(A0);
  int sw2 = analogRead(A1);
  int sw3 = analogRead(A2);

  // turn off if sw3 is touched
  // turn on if sw1 & sw2 are touched
  // turn off if neither condition 1 nor condition two
  if (sw3 >= threshold)
    noTone(buzzerPin);
  else if (sw1 >= threshold && sw2 >= threshold)
    tone(buzzerPin, 500);
  else
    noTone(buzzerPin);
}
