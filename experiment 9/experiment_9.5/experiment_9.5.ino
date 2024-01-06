int speakerPin = 9;
int threshold = 10;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  int sw1 = analogRead(A0);
  int sw2 = analogRead(A1);
  int sw3 = analogRead(A2);
  
  if (sw1 >= threshold) {
    tone(speakerPin, 500);
    delay(200);
    noTone(speakerPin);
    delay(100);
  } else if (sw2 >= threshold) {
    tone(speakerPin, 1000);
    delay(200);
    noTone(speakerPin);
    delay(100);
  } else if (sw3 >= threshold) {
    tone(speakerPin, 1500);
    delay(200);
    noTone(speakerPin);
    delay(100);
  }

}
