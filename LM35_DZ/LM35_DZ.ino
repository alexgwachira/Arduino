const int lm35 = A5;  /* LM35 O/P pin */

void setup() {
  Serial.begin(9600);
}

void loop() {
  int tempval;
  float val;
  tempval = analogRead(lm35);  /* Read Temperature */
  val = (tempval * 4.88); /* Convert adc value to equivalent voltage */
  val = (val/10); /* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");
  Serial.print(val);
  Serial.print(" Degree Celsius\n");
  delay(1000);
}
