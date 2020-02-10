void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  if(Serial.available() > 0) {
    char buffer[16];
    int size = Serial.readBytesUntil('\n', buffer, 12);
    
    if(buffer[0] == 'Y') {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);                       // wait for a second
    }
    
    if(buffer[0] == 'N') {
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(1000);                       // wait for a second
    }
                         
    
  }
}
