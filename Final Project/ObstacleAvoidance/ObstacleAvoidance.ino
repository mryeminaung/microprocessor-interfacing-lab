#include <AFMotor.h>
#include <Servo.h>

Servo myservo;

#define trigPin 7
#define echoPin 5
#define Speed 100

const int left = 13;
const int right = 10;

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(70);
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);
}

void loop() {
  int left_IR = digitalRead(left);
  int right_IR = digitalRead(right);
  int distance_F = UltrasonicRead();

  if (left_IR == LOW && right_IR == LOW) {
    if (distance_F > 30) {
      Serial.println("Forward");
      setSpeed(65);
      Forward();
    } else {
      setSpeed(0);
      Stop();
    }
  } else if (left_IR == HIGH && right_IR == LOW) {
    Serial.println("Left");
    setSpeed(120);
    Left();
  } else if (left_IR == LOW && right_IR == HIGH) {
    Serial.println("Right");
    setSpeed(120);
    Right();
  } else {
    Serial.println("Stop");
    setSpeed(0);
    Stop();
  }
}

int UltrasonicRead() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long cm = (duration * 0.0324) / 2;
  delay(100);
  return cm;
}

void setSpeed(int value) {
  motor1.setSpeed(value);
  motor2.setSpeed(value);
  motor3.setSpeed(value);
  motor4.setSpeed(value);
}

void Forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void Backward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void Left() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void Right() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}