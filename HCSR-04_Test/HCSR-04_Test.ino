int trigPin = 14;    // Trigger
int echoPin = 15;    // Echo
long duration, distance;

#define ena 3
#define in1 4
#define in2 5
#define in3 6
#define in4 7
#define enb 10

#define buzzer 11

void setup() {

  Serial.begin (9600);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.print(distance);
  Serial.print("cm");
  Serial.println();

  if (distance >= 50) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ena, 255);
    analogWrite(enb, 255);

  }
  else {
    analogWrite(ena, 0);
    analogWrite(enb, 0);
    tone (buzzer, 1600);
    delay(70);
    noTone(buzzer);
    delay(70);
    tone (buzzer, 1600);
    delay(70);
    noTone(buzzer);
    delay(70);
    tone (buzzer, 1600);
    delay(70);
    noTone(buzzer);
    delay(70);
    tone (buzzer, 1600);
    delay(100);
    noTone(buzzer);
    delay(350);

  }
  if (distance >= 70) {
    noTone (buzzer, 1600);
  }




  delay(250);
}
