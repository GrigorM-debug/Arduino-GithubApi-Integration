#include <Wire.h>
#include "i2c_device_scanner.h"
#include <LiquidCrystal_I2C.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  
  byte i2cDeviceAddress = scanI2CDevices();

  if(i2cDeviceAddress != 0xFF){
    LiquidCrystal_I2C lcd(i2cDeviceAddress, 20, 4);

    lcd.init();
    lcd.backlight();

    lcd.setCursor(3, 0);
    lcd.print("Everything is working");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
