#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

static int count = 0;

void setup() {
  lcd.begin(16, 2);
}

void loop() {

  lcd.setCursor(2, 0);
  lcd.print("Arduino LAB");

  lcd.setCursor(2, 1);
  lcd.print("Counter: ");
  lcd.print(count);
  count += 1;

  lcd.noDisplay();
  delay(1000);

  lcd.display();
  delay(1000);
}
