#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

#define BT_DISCOVER_TIME 10000

static bool btScanAsync = true;
static bool btScanSync = true;

void btAdvertisedDeviceFound(BTAdvertisedDevice* pDevice) {
  Serial.printf("Found a device asynchronously: %s\n", pDevice->toString().c_str());
}

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Experiment12");
  Serial.println("The device started, now you can pair it with Bluetooth!");

  if (btScanAsync) {
    Serial.println("Starting discoverAsync...");
    if (SerialBT.discoverAsync(btAdvertisedDeviceFound)){
      Serial.println("Findings will be reported in 'btAdvertisedDeviceFound'");
      delay(10000);
      Serial.println("Stopping discoverAsync...");
      SerialBT.discoverAsyncStop();
      Serial.println("stopped");
    } else {
      Serial.println("Error on discoverAsync f.e. not working after a 'connect'");
    }
  }
if (btScanSync) {
    Serial.println("Starting discover...");
    BTScanResults* pResults = SerialBT.discover(BT_DISCOVER_TIME);
    if (pResults)
        pResults->dump(&Serial);
    else
        Serial.println("Error on BT Scan, no result!");
}
}

void loop() {
    delay(100);
}

