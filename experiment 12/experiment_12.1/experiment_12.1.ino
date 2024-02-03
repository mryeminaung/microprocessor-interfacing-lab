#define LED 9
volatile byte state = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  attachInterrupt(0, toggle, LOW);
}

void loop() {
  Serial.println(state);
  digitalWrite(LED, state);
  delay(1000);
}

void toggle() {
  state = !state;
}
