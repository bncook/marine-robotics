#include <Wire.h>
#include "Motor.h"
#include "Arduino_I2C_ESC/Arduino_I2C_ESC.h"

Motor::Motor(int8_t ESCAddress, String name = "motor", double throttle = 1) {

}

Motor::Motor(int8_t ESCAddress, String name = "motor", double throttle = 1) {
    this.name = name;
    this.ESCAddress = ESCAddress;
    this.I2CMotor = Arduino_I2C_ESC(ESCAddress);
    //set the throttle for the I2CMotor
    this.throttle = throttle;
    this.setThrottle(throttle);
}
    
void Motor::setThrottle(double throttle) {

}

double Motor::getThrottleValue() {

}

int8_t Motor::getESCAddress() {

}

void Motor::updateMotor() {

}
    
////////////////////
//GET HEALTH STATS//
////////////////////
    
bool Motor::isAlive() {

}

float Motor::voltage() {

}

float Motor::current() {

}

float Motor::temperature() {

}

int16_t Motor::rpm() {

}
