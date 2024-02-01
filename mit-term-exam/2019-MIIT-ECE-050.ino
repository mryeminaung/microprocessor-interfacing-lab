#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int heaterPin = 6;
int greenLed = 7;
int redLed = 8;
int blueLed = 9;
int fanPin = 10;

void setup() {
  lcd.begin(16, 2);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(heaterPin, OUTPUT);
}

void loop() {
  int val = analogRead(A0);
  float temp = (val * 500.00) / 1023.00;
  int fahTemp = round((temp * (9 / 5) ) + 32);

  if (fahTemp >= 95) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, LOW);
    lcd.setCursor(2, 0);
    lcd.print("Temp Monitor");
    lcd.setCursor(0, 1);
    lcd.print("Temp:");
    lcd.print(fahTemp);
    lcd.print("F(HOT) ");
    digitalWrite(fanPin, HIGH);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("The FAN is ON.     ");
  } else if (fahTemp >= 68 and fahTemp <= 95) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, LOW);
    lcd.setCursor(2, 0);
    lcd.print("Temp Monitor");
    lcd.setCursor(0, 1);
    lcd.print("Temp:");
    lcd.print(fahTemp);
    lcd.print("F(NORMAL)");
    digitalWrite(fanPin, LOW);
    digitalWrite(heaterPin, LOW);
  } else if (fahTemp < 68) {
    digitalWrite(blueLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, LOW);
    lcd.setCursor(2, 0);
    lcd.print("Temp Monitor");
    lcd.setCursor(0, 1);
    lcd.print("Temp:");
    lcd.print(fahTemp);
    lcd.print("F(COLD)  ");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("The HEATER is ON.");
    digitalWrite(heaterPin, HIGH);
  }
  delay(1000);
  lcd.display();
}
