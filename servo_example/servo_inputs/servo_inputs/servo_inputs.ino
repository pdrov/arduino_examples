/*
 * Try to use this as a way of finding out all the inputs that are correct for the 24kg servo
 * Need to find a way to send serial commands and directly control the servo
 * given the microsecond command.
 * 
 * 500 to 2400
 * center = 1450
 * increment by 100
 * increment by 50
 */

#include <Servo.h>

Servo myServo;
int angle;
int pulseWidth;
int analogVal;
int status;
int i;
String command;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); // Digital IO
  myServo.attach(10);
  Serial.begin(9600);
  delay(200);
  myServo.writeMicroseconds(1000);
  delay(100);
  Serial.println("Servo is in safe state.");

}

void loop() {

  for (i=500; i<=2400;){
    myServo.writeMicroseconds(i);
    pulseWidth = myServo.readMicroseconds();
    angle = myServo.read();
    analogVal = analogRead(A0);
    Serial.print("Pulse width = ");
    Serial.print(pulseWidth);
    Serial.print(", Drive angle = ");
    Serial.print(angle);
    Serial.print(", Analog Value = ");
    Serial.println(analogVal);
    delay(1000);
    i = i+100;
    }

}
