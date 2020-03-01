import serial
import sys

"""
Sends 4 PWM Commands to an Arduino for motor control (1 command for each motor)

param: pwm_list - a list of 4 pwm signals to send to the arduino; each pwm signal must
       be in the range [-1, 1]
"""
def send_pwm(pwm_list):
    assert len(pwm_list) == 4
    #constrain the pwm values to range [-1, 1]
    for i in range (0, len(pwm_list)):
        if float(pwm_list[i]) > 1.0: pwm_list[i] = "1.0"
        elif float(pwm_list[i]) < -1.0: pwm_list[i] = "-1.0"

    #write pwm signals to arduino (using ',' as a delimeter)
    out_buffer = ""
    for pwm in pwm_list:
        out_buffer += str(pwm)
        out_buffer += ','
    out_buffer = out_buffer[0:-1]   #strip trailing comma
    print(out_buffer)
    
    ser = serial.Serial()
    ser.port = '/dev/ttyACM0'   #port name of the Arduino
    ser.timeout = 5
    ser.open()
    ser.write(out_buffer)
    ser.close()
    return

if __name__ == "__main__":
    send_pwm(sys.argv[1:])


