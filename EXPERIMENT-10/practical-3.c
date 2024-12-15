int sensorPin = 2;
int BuzzerPin = 4;

void setup()
{
    pinMode(sensorPin , INPUT);
    pinMode(BuzzerPin , OUTPUT);
    Serial.begin(115200);
}

void loop(){
    int sensorvalue=analogRead(sensorPin);
    Serial.print("Light sensor values is: ");
    Serial.println(sensorvalue);
    if (sensorvalue < 1000)
    {
        digitalWrite(BuzzerPin, LOW);
    }
    else
    {
        digitalWrite(BuzzerPin, HIGH);
    }
    delay(1000);
}
