
#define ena 3
#define in1 4
#define in2 5
#define in3 6
#define in4 7
#define enb 10

#define trig 14
#define echo 15
long duration, distance;

#define buzzer 11
#define LED 12


char command = 0;

void setup() {
  Serial.begin(9600);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);


  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);



  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  digitalWrite(trig, LOW);
  delay(5);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();

    switch (command) {
      case 'F': //forward




        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(ena, 200);
        analogWrite(enb, 200);






        break;


      case 'S': //forward torque
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(ena, 255);
        analogWrite(enb, 255);
        break;

      case 'B': //back
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(ena, 120);
        analogWrite(enb, 120);
        break;

      case 'T': //forward
        digitalWrite(in2, HIGH);
        digitalWrite(in1, LOW);
        digitalWrite(in4, HIGH);
        digitalWrite(in3, LOW);
        analogWrite(ena, 255);
        analogWrite(enb, 255);
        break;

      case 'R': //forwardright
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        analogWrite(ena, 150);
        analogWrite(enb, 150);
        break;

      case 'L': //forwardleft
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        analogWrite(ena, 150);
        analogWrite(enb, 150);
        break;

      case 'r': //reverse right
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        analogWrite(ena, 150);
        analogWrite(enb, 150);
        break;

      case 'l': //reverse left
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(ena, 150);
        analogWrite(enb, 150);
        break;

      case 'p': //halt
        analogWrite(ena, 0);
        analogWrite(enb, 0);

        break;



      case 'H': //headlights on
        digitalWrite(LED, HIGH);
        break;

      case 'h': //headlights off
        digitalWrite(LED, LOW);
        break;

      default:
        digitalWrite(in1, HIGH);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, HIGH);

    }
  }
}
