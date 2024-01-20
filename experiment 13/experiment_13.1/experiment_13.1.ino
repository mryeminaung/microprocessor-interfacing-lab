#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {

  int val = analogRead(A0);
  float temp = (val * 500.00) / 1023.00;

  lcd.setCursor(0, 0);

  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.setCursor(0, 1);
  
  if (round(temp) >= 26) {
    digitalWrite(7, HIGH);
    lcd.print("Fan On ");
  } else {
    digitalWrite(7, LOW);
    lcd.print("Fan Off");
  }

  lcd.setCursor(12, 0);
  lcd.print(" C");


}
