const int buzzerPin = 9; // declaring the PWM pin</p><p>void setup() {
  
Serial.begin(9600);
pinMode(buzzerPin, OUTPUT); //addigning pin to Output mode</p><p>}</p><p>void loop() {
  tone(buzzerPin, 50);
  delay(50);
  noTone(buzzerPin);
  delay(100);
}
