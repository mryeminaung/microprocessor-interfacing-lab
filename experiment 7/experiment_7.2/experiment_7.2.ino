int motorPin = 10;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int val = analogRead(A0);
  int speed = map(val, 0, 1023, 0, 255);

  Serial.print("Speed : ");
  Serial.println(speed);

  analogWrite(motorPin, speed);

}
