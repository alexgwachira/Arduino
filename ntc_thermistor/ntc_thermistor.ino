#define ntc A0 //1 ntc pin, the other ntc pin is connected to ground
#define vdr 2 //pin to connect the fixed resistor
#define ntcR 10000 //nomnal resistance @ 25'C
#define ntcT 25 //nominal temperature
#define rate 5 //sampling rate
#define beta 3950 //B-value of the thermistor 
#define vdR 10000 //value of the fixed resistor
int samples = 0;

void setup() {
  pinMode(vdr, OUTPUT);
  Serial.begin(9600);
}

void loop(void) {
  uint8_t i;
  float average;
  samples = 0;

  digitalWrite(vdr, HIGH);
  for (i = 0; i < rate; i++) {
    samples += analogRead(ntc);
    delay(10);
  }
  digitalWrite(vdr, LOW);
  average = 0;
  average = samples / rate;
  Serial.println("\n \n");
  Serial.print("ADC readings ");
  Serial.print(average);

  //Calculate NTC resistance
  average = 1023 / average - 1;
  average = vdR / average;
  Serial.print("Thermistor Resistance ");
  Serial.println(average);

  float temperature;
  temperature = average / ntcR; //(R/Ro)
  temperature = log(temperature); //In(R/Ro)
  temperature /= beta;  //1/B*In(R/Ro)
  temperature += 1.0 / (ntcT + 273.15); //+(1/To)
  temperature = 1.0 / temperature;
  temperature -= 273.15;
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  delay(1000);
}
