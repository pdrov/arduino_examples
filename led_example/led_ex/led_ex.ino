
int status;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); // set built in led as ouput

}

void loop() {
  // put your main code here, to run repeatedly:
  /*
   * analogWrite(pin, duty cycle)
   * duty cycle maps value 0-255 to 0-100%
   */
  analogWrite(13, 127); 
  status = analogRead(13);
  Serial.print(status);
  Serial.print("\n");
}
