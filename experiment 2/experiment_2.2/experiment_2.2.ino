int btn = 2;
int ledPin = 13;
int btnValue = 0;
void setup() {
  pinMode(btn, INPUT);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  btnValue = digitalRead(btn);
  if (btnValue == 1) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
