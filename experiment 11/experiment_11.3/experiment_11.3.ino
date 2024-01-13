#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

static int count = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  float value = analogRead(A0);
  float voltage = (value / 1023) * 5.0;
  Serial.println(voltage);
  
  lcd.setCursor(4, 0);
  lcd.print("Voltmeter");

  lcd.setCursor(1, 1);
  lcd.print("Voltage = ");
  lcd.print(voltage);
  lcd.print("V");
  
  lcd.display();
  delay(1000);
}
