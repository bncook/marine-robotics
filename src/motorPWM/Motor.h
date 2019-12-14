#include <Wire.h>
#include "Arduino_I2C_ESC/Arduino_I2C_ESC.h"

class Motor {
  private:
    String name;        //if you want to give the motor a cool name
    double PWM_Signal;  //between 0 and 1
    int8_t direction;   //1 for forward, 0 for backward
    int8_t ESCAddress;
    Arduino_I2C_ESC I2CMotor;
  
  public:
    /**/
    Motor(String name, int8_t ESCAddress);
    
    /**/
    void setPWMSignal();

    /**/
    void setDirection();

    /**/
    double getPWMSignal();

    /**/
     int8_t getDirection();

    /**/
    int8_t getESCAddress

    /**/
    void updateMotor();
    
    ////////////////////
    //GET HEALTH STATS//
    ////////////////////
    
    /*Returns true if ESC is connected*/
    bool isAlive();

    /* Returns voltage measured by the ESC in volts */
    float voltage();

    /* Returns current measured by the ESC in amps */
    float current();

    /* Returns temperature measured by the ESC in degree Celsius */
    float temperature();

    /* Returns RPM of the motor. Note that this measurement will be
     * more accurate if the I2C data is read slowly. */
    int16_t rpm();
}
