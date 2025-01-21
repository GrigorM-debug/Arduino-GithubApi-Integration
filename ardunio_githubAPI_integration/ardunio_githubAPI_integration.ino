#include <Wire.h>
#include "i2c_device_scanner.h"
#include <LiquidCrystal_I2C.h>
#include "Arduino_LED_Matrix.h"
#include "led_matrix_frames.h"

#include "arduino_secrets.h"
#include <WiFiS3.h>

ArduinoLEDMatrix matrix;

int status = WL_IDLE_STATUS; // The WiFi radio's status

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);

  byte i2cDeviceAddress = scanI2CDevices();

  if(i2cDeviceAddress > 0){
    LiquidCrystal_I2C lcd(i2cDeviceAddress, 20, 4);
    
    //Think about moving it to a function
    //
    //Check for the Wifi module
    if(WiFi.status() == WL_NO_MODULE){
      Serial.println("Communication with Wifi Module failed.");
      //don't contunue
      while(true);
    }

    //Check the Firmware version
    String firmwareVersion = WiFi.firmwareVersion();
    if(firmwareVersion < WIFI_FIRMWARE_LATEST_VERSION){
      Serial.println("Upgrade the firmware version");
    }

    //Connecting to Wifi network
    while(status != WL_CONNECTED){
      Serial.println("Connecting to WPA SSID: ");
      Serial.print(SECRET_SSID);
      Serial.println("\n");

      //Wifi search animation
      matrix.loadSequence(LEDMATRIX_ANIMATION_WIFI_SEARCH);
      matrix.begin();
      matrix.play(true);

      status = WiFi.begin(SECRET_SSID, SECRET_PASSWORD);

      // wait 10 seconds for connection:
      delay(10000);
    }

    if(status == WL_CONNECTED){
      Serial.print("Succsselfully connected to WPA SSID: ");
      Serial.println(SECRET_SSID);

      matrix.loadFrame(LEDMATRIX_LIKE);
      matrix.begin();
      
      lcd.init();
      lcd.backlight();

      lcd.setCursor(0, 0);          
      lcd.print("Succssefully connected to WPA SSID: ");        
      lcd.setCursor(0, 3);          
      lcd.print(SECRET_SSID);
    } 
    else{
      Serial.print("Failed to connect to WPA SSID: ");
      Serial.println(SECRET_SSID);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
