int pmwled = 9;
byte brightness = 0;

void setup() {
  pinMode(pmwled, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    brightness = Serial.read();
    if (brightness >= '0' && brightness <= '9');
    brightness = 25 * (brightness - '0');
    Serial.println(brightness);
    Serial.print(" ");

    analogWrite(pmwled, brightness);
  }

}
