#include <Servo.h>

//motor pins
byte rightPin = 9;
byte leftPin = 11;

//motors
Servo right;
Servo left;

void setup() {
  right.attach(rightPin);
  right.writeMicroseconds(1500); //send stop signal to ESC
  left.attach(leftPin);
  left.writeMicroseconds(1500);  //send stop signal to ESC
  delay(1000);  //delay to allow the ESC to recognize the stopped signal
}

void loop() {
  int rightSignal = 1700;
  int leftSignal = 1700;

  right.writeMicroseconds(rightSignal);
  left.writeMicroseconds(leftSignal);
}
