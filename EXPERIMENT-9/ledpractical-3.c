const int ledpin = 2;
const int buttonpin = 23;
int buttonstate = 0;

void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpin, INPUT);
}

void loop() {
  buttonstate = digitalRead(buttonpin);
  if(buttonstate == LOW) {
    digitalWrite(ledpin, HIGH);
  } else {
    digitalWrite(ledpin, LOW);
  }
}
