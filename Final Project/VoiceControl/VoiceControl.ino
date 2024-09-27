#include <AFMotor.h>
#include <Servo.h>

Servo myservo;

#define Speed 100

char value;

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(70);
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);
}

void loop() {
  if (Serial.available() > 0) {
    value = Serial.read();
    
    VoiceControl();
  }
}

void VoiceControl() {
  setSpeed(60);
  switch (value) {
    case 'F':
      Forward();
      break;
    case 'B':
      Backward();
      break;
    case 'L':
      Left();
      break;
    case 'R':
      Right();
      break;
    case 'S':
      Stop();
      break;
    case '^':
      setSpeed(90);
      break;
    case '*':
      setSpeed(110);
      break;
    case '&':
      setSpeed(60);
      break;
  }
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