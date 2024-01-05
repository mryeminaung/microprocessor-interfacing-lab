int buzzerPin = 9;

// First melody: C5, D5, E5, F5, G5, A5, B5, C6
// do, re, mi, fa, so, la, ti, do
int firstMelody[] = {523, 587, 659, 698, 783, 880, 987, 1046};

// Second melody: G5, A5, B5, C6, D5, E5, F5, G5
// so, la, ti, do, re, mi, fa, so
int secondMelody[] = {783, 880, 987, 1046, 587, 659, 698, 783 };

int duration = 200;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    playNote(firstMelody[i]);
  }
  delay(1000);

  for (int i = 0; i < 8; i++) {
    playNote(secondMelody[i]);
  }
  delay(1000);
}

void playNote(int frequency) {
  tone(buzzerPin, frequency, duration);
  delay(duration);
  noTone(buzzerPin);
}
