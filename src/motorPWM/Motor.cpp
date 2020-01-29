//#include <Wire.h>
#include "Motor.h"
#include "Arduino_I2C_ESC/Arduino_I2C_ESC.h"

Motor::Motor(uint8_t ESCAddress, String name = "motor", double throttle = 1.0) {
    this->name = name;
    this->ESCAddress = ESCAddress;
    this->I2CMotor = new Arduino_I2C_ESC(ESCAddress);
    //set the throttle for the I2CMotor
    this->throttle = throttle;
    this->setThrottle(throttle);
}
    
void Motor::setThrottle(double throttle) {
  this->I2CMotor->set(int(throttle*32767));
}

double Motor::getThrottleValue() {
  return this->throttle;
}

int8_t Motor::getESCAddress() {
  return this->ESCAddress;
}

void Motor::updateMotor() {
  this->I2CMotor->update();
}
    
////////////////////
//GET HEALTH STATS//
////////////////////
    
bool Motor::isAlive() {
 return this->I2CMotor->isAlive();
}

float Motor::voltage() {
  return this->I2CMotor->voltage();
}

float Motor::current() {
  return this->I2CMotor->current();
}

float Motor::temperature() {
  return this->I2CMotor->temperature();
}

int16_t Motor::rpm() {
  return this->I2CMotor->rpm();
}
