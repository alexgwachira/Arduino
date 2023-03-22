#define relay_1 10
#define relay_2 8
#define LDR A0


char btdata = 0;
int ldrvalue = 0;


void setup() {
  
  pinMode (relay_1, OUTPUT);
  pinMode (relay_2, OUTPUT);
  Serial.begin(9600);

  digitalWrite (relay_1, HIGH);
  digitalWrite (relay_2, HIGH);

}

void loop() {
  ldrvalue = analogRead(LDR);
  Serial.println (ldrvalue);

  if (Serial.available() > 0) {
    btdata = Serial.read();
    Serial.println(btdata);

    switch (btdata) {
      case 'A': //turn on relay_1
        digitalWrite (relay_1, LOW);
        break;
      case 'a': //turn off relay_1
        digitalWrite (relay_1, HIGH);
        break;

      case 'B': //turn on relay_2
        digitalWrite (relay_2, LOW);
        break;
      case 'b': //turn off relay_2
        digitalWrite (relay_2, HIGH);
        break;
    }

  }
}
