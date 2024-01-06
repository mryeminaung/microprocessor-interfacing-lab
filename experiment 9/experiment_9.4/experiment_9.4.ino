#include "pitches.h"

int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
int durations[] = {250, 125, 125, 250, 250, 250, 250, 250};

int speakerPin = 9;
int threshold = 10;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  int sw1 = analogRead(A0);
  int sw2 = analogRead(A1);

  if (sw2 >= threshold) {
    noTone(speakerPin);
  } else if (sw1 >= threshold) {
    playMelody();
  } else {
    noTone(speakerPin);
  }
}

void playMelody() {
  for (int note = 0; note < 8; note++) {
    int delayTime = durations[note] * 1.30;
    tone(speakerPin, melody[note]);
    delay(delayTime);
    noTone(speakerPin);
    delay(delayTime);
  }
}
