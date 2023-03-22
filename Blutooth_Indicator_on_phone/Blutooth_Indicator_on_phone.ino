#define trigger 2
#define echo 3
long echotime;
float distance;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, OUTPUT);
  digitalWrite(trigger, LOW);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);


  echotime = pulseIn(echo, HIGH);
  distance = 0.0001 * ((float)echotime * 340.0) / 2.0;

  //send over bluetooth
  Serial.print("*D" + String(distance, 1) + "*");
  if (distance < 20 )Serial.print("*LR255G0B0*"); //Red
  if (distance >= 20 && distance <= 50 )Serial.print("*LR255G200B0*"); //Orange
  if (distance > 50 )Serial.print("*LR0G255B0*"); //Green
  delay (50);
}
