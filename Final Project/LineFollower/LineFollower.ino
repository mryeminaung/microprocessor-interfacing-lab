#include <AFMotor.h>
#include <Servo.h>

Servo myservo;

#define left 13
#define right 10

#define Speed 100

int mode = 3;
char value;

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
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);
}

void loop() {
  if (Serial.available() > 0) {
    value = Serial.read();

    // if (value == 'W') {
    //   mode = 1;
    // } else if (value == 'w') {
    //   mode = 2;
    // }

    // switch (mode) {
    // case 1:
    // LineFollower();
    // break;
    // case 2:
    BluetoothControl();
    //     break;
    //   default:
    //     Stop();
    // }
  }
}

void BluetoothControl() {
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
    case 'G':
      ForwardLeft();
      break;
    case 'I':
      ForwardRight();
      break;
    case 'H':
      BackwardLeft();
      break;
    case 'J':
      BackwardRight();
      break;
    case '1':
      setSpeed(50);
      break;
    case '2':
      setSpeed(70);
      break;
    case '3':
      setSpeed(90);
      break;
    case '4':
      setSpeed(110);
      break;
    case '5':
      setSpeed(130);
      break;
    case '6':
      setSpeed(150);
      break;
    case '7':
      setSpeed(170);
      break;
    case '8':
      setSpeed(180);
      break;
    case '9':
      setSpeed(190);
      break;
    case 'q':
      setSpeed(200);
      break;
    default:
      Stop();
  }
}

void LineFollower() {
  int left_IR = digitalRead(left);
  int right_IR = digitalRead(right);

  if (left_IR == LOW && right_IR == LOW) {
    setSpeed(65);
    Forward();
  } else if (left_IR == HIGH && right_IR == LOW) {
    setSpeed(140);
    Left();
  } else if (left_IR == LOW && right_IR == HIGH) {
    setSpeed(140);
    Right();
  } else {
    setSpeed(0);
    Stop();
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

void ForwardRight() {
  setSpeed(80);
  Forward();
  delay(20);
  setSpeed(180);
  Right();
  delay(10);
}

void ForwardLeft() {
  setSpeed(80);
  Forward();
  delay(20);
  setSpeed(180);
  Left();
  delay(10);
}

void BackwardRight() {
  setSpeed(80);
  Backward();
  delay(20);
  setSpeed(180);
  Left();
  delay(10);
}

void BackwardLeft() {
  setSpeed(80);
  Backward();
  delay(20);
  setSpeed(180);
  Left();
  delay(10);
}
