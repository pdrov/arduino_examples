/*
 * This example is to test the 20kg servo with PWM inputs. 
 * 
 */

#include <Servo.h>

Servo myServo;
int angle;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(10);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  myServo.write(90);
  angle = myServo.read();
  Serial.print(angle);
  Serial.print("\n");
  delay(1000);
  myServo.write(0);
  angle = myServo.read();
  Serial.print(angle);
  Serial.print("\n");
}
