#define buzzer 11

void setup() {
 pinMode(buzzer, OUTPUT);

}

void loop() {
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
