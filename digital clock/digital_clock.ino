#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

static int hour = 12;
static int minute = 58;
static int second = 55;

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{

  lcd.setCursor(2, 0);

  lcd.print("Digital Clock");

  second += 1;
  if (second == 60)
  {
    second = 0;
    minute += 1;
    if (minute == 60)
    {
      minute = 0;
      hour += 1;
      if (hour > 23)
      {
        hour = 0;
      }
    }
  }

  lcd.setCursor(2, 1);
  digital_clock(hour);

  lcd.setCursor(4, 1);
  lcd.print(":");

  lcd.setCursor(5, 1);
  digital_clock(minute);

  lcd.setCursor(7, 1);
  lcd.print(":");

  lcd.setCursor(8, 1);
  digital_clock(second);

  lcd.setCursor(11, 1);
  if (hour >= 12)
  {
    lcd.print("PM");
  }
  else
  {
    lcd.print("AM");
  }

  lcd.display();
  delay(1000);
}

void digital_clock(int timer)
{
  if (timer >= 10)
  {
    lcd.print(timer);
  }
  else if (timer < 10)
  {
    lcd.print(0);
    lcd.print(timer);
  }
}
