//Infrared Function
void infrared() {
  Serial.print("IRCode: ");
  Serial.println(results.value, DEC);

  //fan
  if (results.value == 16660679) {
    digitalWrite (fan, HIGH); //CH+
  }
  else if (results.value == 16650479) {
    digitalWrite (fan, LOW); //`CH -
  }

  //ac lights
  else if (results.value == 16683119) {
    digitalWrite (relay1, LOW); //Vol+
  }
  else if (results.value == 16687199) {
    digitalWrite (relay1, HIGH); //Vol-
  }

  //resume
  irrecv.resume();

}
