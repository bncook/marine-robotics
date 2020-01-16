#include <Wire.h>
#include "Arduino_I2C_ESC/Arduino_I2C_ESC.h"

/* Represents a Motor for MIT Marine Robotics Team AUV
 * 
 * The class acts as a wrapper for the Arduino_I2C_ESC class
 * and provides a convenient functions to set the throttle value
 * (the PWM signal) to the Motor, read health stats of the Motor, etc. 
 */
class Motor {
  private:
    String name;        //if you want to give the motor a cool name
    double throttle;    //between -1 and 1
    int8_t ESCAddress;
    Arduino_I2C_ESC I2CMotor;
  
  public:
    /* Creates a new Motor object with the specified name and ESC Address
     * param: 'ESCAddress', the ESCAddress of the Motor
     * param: 'name', the name of the Motor; optional parameter
     * param: 'throttle', the throttle of the Motor; between -1 and 1
     *         the motor will move forward for positive 'throttle' values
     *         and backward for negative 'throttle' values; the PWM signal
     *         of the throttle is equal to the magnitude of 'throttle'
     *         optional parameter
     */
    Motor(int8_t ESCAddress, String name = "motor", double throttle = 1);
    
    /* Sets the throttle of the Motor to the given pwm signal
     * param: 'throttle', the pwm signal to set the motor throttle to;
     *         must be between -1 and 1 (-1 <= 'throttle' <= 1), 1 for
     *         full forward, -1 for full reverse
     */
    void setThrottle(double throttle);

    /* Gets the current value of the motor throttle*/
    double getThrottleValue();

    /* Gets the ESCAddress of the motor*/
    int8_t getESCAddress();

    /* Read new data from the ESC motor
     * (See the documentation for Arduino_I2C_ESC.update())
     */
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
