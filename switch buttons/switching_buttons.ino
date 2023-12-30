int ledPin = 13;
int btn1 = 3;
int btn2 = 2;
int s1 = 0;
int s2 = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}

void loop() {
  s1 = digitalRead(btn1);
  s2 = digitalRead(btn2);

  if (s1 == 1)
    digitalWrite(ledPin, HIGH);
  if (s2 == 1)
    digitalWrite(ledPin, LOW);

  delay(100);
}
