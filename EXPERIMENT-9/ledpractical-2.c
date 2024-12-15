int ledpin = 25 ;    // the PWM pin the LED is attached
int brightness = 0;  // how bright the led is
int fadeamount = 5;  // how many points to fade the LED by

void setup() {
  pinMode(ledpin , OUTPUT);
}

void loop() {
  analogWrite(ledpin , brightness); //0-255
  brightness += fadeamount;
  if( brightness <= 0 || brightness >= 255) {
    fadeamount = -fadeamount ;
  }
  delay(1); // 1 millisecond
}
