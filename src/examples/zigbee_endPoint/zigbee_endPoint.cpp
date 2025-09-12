#include "ZigbeeCore.h"
#include "ep/ZigbeeLight.h"

#define LED_PIN LED_BUILTIN
#define ZIGBEE_LIGHT_ENDPOINT 10

ZigbeeLight zbLight(ZIGBEE_LIGHT_ENDPOINT);

void setLED(bool value) {
  digitalWrite(LED_PIN, value);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  zbLight.setManufacturerAndModel("Espressif", "ZBLightBulb");       // Identify device
  zbLight.onLightChange(setLED);                                    // Callback for on/off
  Zigbee.addEndpoint(&zbLight);                                     // Register endpoint
  Zigbee.begin();  // Starts Zigbee stack (role is determined by Tools->Zigbee Mode) 
}
