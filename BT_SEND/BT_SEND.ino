#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

#define trigger 2
#define echo 3
long echotime;
long distance;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trigger, LOW);
  digitalWrite(8, HIGH);

  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);


  echotime = pulseIn(echo, HIGH);
  distance = (echotime / 2) / 29.1;

  //send over bluetooth
  mySerial.print("1234");
  mySerial.print(",");
  mySerial.print("1234.0");
  mySerial.print(",");
  mySerial.print("1234 hPa");
  mySerial.print(",");
  mySerial.print("500 ml/s");
  mySerial.print(",");
  mySerial.print(distance);
  mySerial.print(",");

  delay (20);
}
