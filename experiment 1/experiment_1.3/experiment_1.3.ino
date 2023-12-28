
int ledPin8 = 8;
int ledPin9= 9;

void setup() {
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
}

void loop() {
  led_light(ledPin8);
  led_light(ledPin9);
}

void led_light(int pinNo) {
  digitalWrite(pinNo, HIGH);
  delay(1000);
  digitalWrite(pinNo, LOW);
  delay(1000);
}
