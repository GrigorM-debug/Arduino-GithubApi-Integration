#include <Wire.h>
#include "i2c_device_scanner.h"
#include "arduino_secrets.h"
#include <LiquidCrystal_I2C.h>
#include "wifi_connection.h"
#include "arduino_LED_matrix_animations.h"
#include "web_server.h"

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(115200);

  byte i2cDeviceAddress = scanI2CDevices();

  if(i2cDeviceAddress > 0){
    LiquidCrystal_I2C lcd(i2cDeviceAddress, 20, 4);
    
    //Connect to Wifi
    int wifiConnectionStatus = connectedToWifi(
                                  SECRET_SSID, 
                                  SECRET_PASSWORD
                                );
        
    if(wifiConnectionStatus == 3){
      startServer();
      //server.begin();
      // lcd.init();
      // lcd.backlight();
      // lcd.print("Connected");
    } 
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  handleClient();
}
