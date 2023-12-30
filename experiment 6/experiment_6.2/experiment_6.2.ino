void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void loop() {
  int val = analogRead(A0);

  float x = map(val, 0, 1023, 0, 255);

  int percentage = (x / 255) * 100; 

  Serial.print("Intensity: ");
  Serial.print(percentage);
  Serial.println(" %");

  analogWrite(10, x);

  delay(1000);

}
