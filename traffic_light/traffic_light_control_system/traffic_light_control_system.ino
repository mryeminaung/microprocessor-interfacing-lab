
int horiz_ledRed13 = 13;
int horiz_ledGreen12 = 12;
int horiz_ledYellow11 = 11;

int verti_ledRed7 = 7;
int verti_ledGreen6 = 6;
int verti_ledYellow5 = 5;

void setup() {
  pinMode(horiz_ledRed13, OUTPUT);
  pinMode(horiz_ledGreen12, OUTPUT);
  pinMode(horiz_ledYellow11, OUTPUT);

  pinMode(verti_ledRed7, OUTPUT);
  pinMode(verti_ledGreen6, OUTPUT);
  pinMode(verti_ledYellow5, OUTPUT);
}

void loop() {
  digitalWrite(horiz_ledRed13, HIGH);
  digitalWrite(verti_ledGreen6, HIGH);
  delay(3000);
  digitalWrite(verti_ledGreen6, LOW);
  digitalWrite(verti_ledYellow5, HIGH);
  delay(1000);
  digitalWrite(verti_ledYellow5, LOW);
  digitalWrite(horiz_ledRed13, LOW);

  digitalWrite(horiz_ledGreen12, HIGH);
  digitalWrite(verti_ledRed7, HIGH);
  delay(3000);
  digitalWrite(horiz_ledGreen12, LOW);
  digitalWrite(horiz_ledYellow11, HIGH);
  delay(1000);
  digitalWrite(horiz_ledYellow11, LOW);
  digitalWrite(verti_ledRed7, LOW);
}
