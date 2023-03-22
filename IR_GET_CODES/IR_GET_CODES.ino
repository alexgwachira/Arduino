#include <IRremote.h>
#include <IRremote.hpp>

#define irpin 5
IRrecv irrecv(irpin);
decode_results results;

void setup() {
  pinMode(irpin, INPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);

}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Code: ");
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  delay(25);
}
