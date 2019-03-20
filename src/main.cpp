#include <Arduino.h>
#define SerialDebug Serial

#define vccCorrection 0.08

ADC_MODE(ADC_VCC);
RF_MODE(RF_CAL);
/**
RF_DEFAULT = 0, // RF_CAL or not after deep-sleep wake up, depends on init data byte 108.
RF_CAL = 1,      // RF_CAL after deep-sleep wake up, there will be large current.
RF_NO_CAL = 2,   // no RF_CAL after deep-sleep wake up, there will only be small current.
RF_DISABLED = 4 // disable RF after deep-sleep wake up, just like modem sleep, there will be the smallest current.
*/

void setup() {
  SerialDebug.begin(115200);
  SerialDebug.println("Serial initialized");
  delay(1000);

  //SerialDebug.println(ESP.getVcc());
}

void loop() {
  delay(3000);
  auto vcc = ESP.getVcc();
  SerialDebug.printf("VCC: %f\r\n", (float)vcc/1024-vccCorrection);
}
