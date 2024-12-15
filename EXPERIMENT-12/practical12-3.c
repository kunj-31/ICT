#include "BluetoothSerial.h"
# if !defined(CONFIG_BT_ENABLED)|| !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run 'make menuconfig' to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the chip ESP32 chip.
#endif

BluetoothSerial SerialBT;
const int led=2;
byte BTData;

void setup()
{
  pinMode(led,OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("Experiment12");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop()
{
  if(Serial.available())
  {
    SerialBT.write(Serial.read());
  }
  if(SerialBT.available())
  {
    BTData = SerialBT.read();
    Serial.write(BTData);
  }
  if(BTData == '1')
  {
    digitalWrite(led, HIGH);
  }
  else if(BTData == '0')
  {
    digitalWrite(led, LOW);
  }
  delay(20);
}
