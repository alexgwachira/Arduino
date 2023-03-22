#define potpin A0
#define fanpin 9
float potvalue = 0;
int threshold = 90;


void setup() {
  Serial.begin(9600);
  pinMode(fanpin, OUTPUT);
  analogWrite(fanpin, 0);

}

void loop() {
  potvalue = analogRead(potpin);

  potvalue = map(potvalue, 0, 1023, 0, 255);
  Serial.print("Speed: ");
  Serial.println(potvalue);

  if (potvalue < 90) {
    digitalWrite(fanpin, LOW);
  }
  else {
    analogWrite(fanpin, potvalue);
  }

  delay(10);
}
