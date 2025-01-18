#include <Wire.h>
#include "i2c_device_scanner.h"

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  
  byte i2cDeviceAddress = scanI2CDevices()

  if(i2cDeviceAddress != 0xFF){
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
