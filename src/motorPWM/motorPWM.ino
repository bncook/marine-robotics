#include "Motor.h"

//int motorFourPWM = 3;
//int dutyCycle = 128;

uint8_t rightAddress = 0x29;
Motor right = new Motor(rightAddress);

void setup() {
//  pinMode(motorFourPWM, OUTPUT);
  right.setThrottle(1.0);
}

void loop() {
//  analogWrite(motorFourPWM, dutyCycle);
  right.updateMotor();
  delay(250);
}
