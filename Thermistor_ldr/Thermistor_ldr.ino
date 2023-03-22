#include <IRremote.h>
#include <IRremote.hpp>

#define ldr A0   //controls lights
#define therm A1 //controls fan
#define fan 6
#define relay1 7 //lights on ac
#define relay2 8
#define irpin 2 //ir receiver for remote control
#define led 10

IRrecv irrecv(irpin);
decode_results results;

void setup() {
  pinMode(fan, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(irpin, INPUT);

  digitalWrite (relay1, HIGH);
  digitalWrite (relay2, HIGH);

  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop() {
  if (irrecv.decode(&results))
  {
    infrared();
  }

  else {
    //LDR Control
    int ldrvalue = analogRead(ldr);
    if (ldrvalue < 150) {
      digitalWrite(led, HIGH);
    }
    else {
      digitalWrite(led, LOW);
    }


    //THERMISTOR Control
    int thermvalue = analogRead(therm);



    Serial.print("LDR: ");
    Serial.println(ldrvalue);
    Serial.print("THERMISTOR: ");
    Serial.println(thermvalue);
    delay(500);
  }


  delay(10);
}
