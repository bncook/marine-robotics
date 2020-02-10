import serial

ser = serial.Serial()
ser.port = '/dev/ttyACM0'   #port name of the Arduino
ser.timeout = 5

ser.open()
while True:
    led_on = raw_input("Do you want the LED on?")[0]
    if led_on in 'yY':
        ser.write("YES")
    if led_on in 'nN':
        ser.write("NO")
    if led_on in 'qQ':
        break
ser.close()