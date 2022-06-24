/*
 * This example is to test the 20kg servo with PWM inputs. 
 * 
 */

#include <Servo.h>

Servo myServo;
int angle;
int status;
int i;
String command;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(10);
  pinMode(13, OUTPUT); // set built in led as ouput
  Serial.begin(9600);
  Serial.println("Enter command:");

}

void loop() {
   if (Serial.available()){
    command = Serial.readStringUntil('\n');
    if (command.equals("cw")){
      fullyClockwise();
     }
     else if (command.equals("ccw")){
      fullyCounterClockwise();
     }
     else if (command.equals("middle")){
      middle();
     }
     else{
      Serial.println("Invalid command");
     } 
    }
}

void fullyClockwise(){
  myServo.writeMicroseconds(2000);
  delay(100);
}

void fullyCounterClockwise(){
  myServo.writeMicroseconds(1000);
  delay(100);
}

void middle(){
  myServo.writeMicroseconds(1500);
  delay(100);
}
