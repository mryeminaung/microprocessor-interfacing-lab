#define LED1 9
#define LED2 10
#define SW1 2
#define SW2 3

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, 0); // LED off
  digitalWrite(LED2, 0); // LED off
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  attachInterrupt(0, ISR0, FALLING);
  // interrupt 0 digital pin 2 connected SW0  attachInterrupt(1, ISR1, RISING);
  // interrupt 1 digital pin 3 connected SW1
}
void loop() {
  // 18
} // end loop

void myDelay(int x) {
  for (int i = 0; i <= x; i++)
  {
    delayMicroseconds(1000);
  }
}

// change state of an output pin
void toggle(byte pinNum) {
  byte pinState = !digitalRead(pinNum);  digitalWrite(pinNum, pinState);
}

void ISR0()
{
  toggle(LED1);
}

void ISR1() {
  detachInterrupt(0); // not needed!
  toggle(LED2);
  myDelay(5000); // 5 sec.
  toggle(LED2);
  attachInterrupt(0,  ISR0,  RISING);  //  not needed
  flag1 = 0; // clear flag
}
