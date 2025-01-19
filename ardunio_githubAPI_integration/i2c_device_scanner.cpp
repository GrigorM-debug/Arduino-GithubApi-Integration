#include "i2c_device_scanner.h"

byte scanI2CDevices(){
  byte error, address;

  Serial.println("I2C device scanning...");

  for(address = 1; address < 127; address++){
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0){
      Serial.print("I2C device found at address 0x");
      if (address < 16){
        Serial.print("0");
      }

      Serial.print(address,HEX);
      Serial.println(" !");

      return address;
    }
    else if (error == 4){
      Serial.print("Unknown error at address 0x");
      
      if (address < 16){
        Serial.print("0");
      }

      Serial.println(address,HEX);
    }
    else{
      Serial.println("No I2C devices found");
    }
  }
}