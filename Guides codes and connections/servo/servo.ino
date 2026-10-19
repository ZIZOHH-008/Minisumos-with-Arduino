#include <Servo.h>
Servo servoShoot;


void setup() {
  servoShoot.attach(9);
  servoShoot.write(0);
  delay(1000);
}



void loop() {
  servoShoot.write(90);
  delay(2000);

  servoShoot.write(0);
  delay(2000);
}