int motorPin = 10;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int speed = Serial.parseInt();

    Serial.print("Speed : ");
    Serial.println(speed);

    if (speed >= 0 && speed <= 255) {
      analogWrite(motorPin, speed);
      Serial.println("Motor is ON");
    } else {
      analogWrite(motorPin, 0);
      Serial.println("Motor is OFF");
    }
  }
}
