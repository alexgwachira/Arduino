#define ldr A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int ldrvalue = analogRead(ldr);
  Serial.println(ldrvalue);
  delay(500);
}
