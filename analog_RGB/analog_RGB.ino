#define redpin 5
#define greenpin 6
#define bluepin 3
int r;
int g;
int b;
int fade = A0;
int fadeval;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
}

void loop() {
  fadeval = analogRead(fade);
  fadeval = map(fadeval, 0, 1023, 0, 1000);
  //fadeval from bluepin to violet
  for (r = 0; r < 256; r++) {
    analogWrite(redpin, r);
    delay(fadeval);
  }

  //fadeval from violet to redpin
  for (b = 255; b > 0; b--) {
    analogWrite(bluepin, b);
    delay(fadeval);
  }

  //fadeval from redpin to yellow
  for (g = 0; g < 256; g++) {
    analogWrite(greenpin, g);
    delay(fadeval);
  }

  //fadeval from yellow to greenpin
  for (r = 255; r > 0; r--) {
    analogWrite(redpin, r);
    delay(fadeval);
  }

  //fadeval from greenpin to teal
  for (b = 0; b < 256; b++) {
    analogWrite(bluepin, b);
    delay(fadeval);
  }

  //fadeval from teal to bluepin
  for (g = 255; g > 0; g--) {
    analogWrite(greenpin, g);
    delay(fadeval);
  }

}
