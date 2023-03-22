#include <IRremote.h>
#include <IRremote.hpp>

#define bulb 8
#define irpin 5
IRrecv irrecv(irpin);
decode_results results;
char bt;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(irpin, INPUT);
  pinMode(bulb, OUTPUT);

  digitalWrite(bulb, HIGH);
}

void loop() {
  if (irrecv.decode(&results)) {
    infrared();
  }
  if (Serial.available() > 0) {
    bluetooth();
  }
}

//Infrared Function
void infrared() {
  Serial.print("Code: ");
  Serial.println(results.value, DEC);

  if (results.value == 33746959) {  // |<<
    digitalWrite (bulb, LOW);
  }
  if (results.value == 33697999) {  // |>>
    digitalWrite (bulb, HIGH);
  }
  irrecv.resume();

}

void bluetooth() {
  bt = Serial.read();
  Serial.println(bt);

  switch (bt) {
    case 'a' :
      digitalWrite(bulb, LOW);
      break;
    case 'b':
      digitalWrite(bulb, HIGH);
      break;
  }
  delay(25);
}
