int red = 9;
int blue = 10;
int green = 11;

int redvalue = 0;
int bluevalue = 0;
int greenvalue = 0;

char btvalue;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);

  Serial.begin (9600);
}

void loop() {
  if (Serial.available() > 0) {
    btvalue = Serial.read();
    if (btvalue == 'R') redvalue = Serial.parseInt();
    if (btvalue == 'B') bluevalue = Serial.parseInt();
    if (btvalue == 'G') greenvalue = Serial.parseInt();
  }
  analogWrite(red, redvalue);
  analogWrite(blue, bluevalue);
  analogWrite(green, greenvalue);
  delay(10);

}
