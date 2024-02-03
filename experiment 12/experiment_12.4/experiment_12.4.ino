#define LED1 9
#define LED2 10
#define SW1 2
#define SW2 3

volatile byte flag0 = LOW; // declare IRQ flag
volatile byte flag1 = LOW; // declare IRQ flag

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, 0); // LED off digitalWrite(LED2, 0); // LED off  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  attachInterrupt(0, ISR0, FALLING);  attachInterrupt(1, ISR1, RISING);
}

void loop() {
  noInterrupts()toggle(LED2);
  myDelay(2000);
  toggle(LED2);
  myDelay(2000);
  interrupts();
  // no other interrupt work except from here to begin loop.
} // end loop

void myDelay(int x) {
  for (unsigned int i = 0; i <= x; i++)  {
    delayMicroseconds(1000);
  }
}

// change state of an output pin void toggle(byte pinNum) {
byte pinState = !digitalRead(pinNum);  digitalWrite(pinNum, pinState);
}

void ISR0()
{
  toggle(LED1);
}

void ISR1() {
  toggle(LED2);
  myDelay(5000); // 5 sec.  toggle(LED2);
  flag1 = 0; // clear flag
}
