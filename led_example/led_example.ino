/*
 * Expanded code to include serial inputs to control LED 
 * on -> turns on LED
 * off -> turns off LED
 * blink -> turns on/off LED ten times
 */


int status;
int i;
String command;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); // set built in led as ouput
  Serial.begin(9600);
  Serial.println("Enter command:");

}

void loop() {
  // put your main code here, to run repeatedly:
  /*
   * analogWrite(pin, duty cycle)
   * duty cycle maps value 0-255 to 0-100%
   */
   if (Serial.available()){
    command = Serial.readStringUntil('\n');
    if (command.equals("blink")){
      blinkLED();
     }
     else if (command.equals("on")){
      on();
     }
     else if (command.equals("off")){
      off();
     }
     else{
      Serial.println("Invalid command");
     } 
    }
}

void blinkLED(){
  for (i=0; i<=10; i++){
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100); // Second delay is needed otherwise timing issue occurs and breaks function
    i;
    }
}

void on(){
  digitalWrite(13, HIGH);
}

void off(){
  digitalWrite(13, LOW);
}
