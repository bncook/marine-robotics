int motorFourPWM = 3;
int dutyCycle = 128;

void setup() {
  pinMode(motorFourPWM, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(motorFourPWM, dutyCycle);
}
