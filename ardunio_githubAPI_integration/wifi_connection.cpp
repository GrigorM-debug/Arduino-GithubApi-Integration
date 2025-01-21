#include "wifi_connection.h"

int status = WL_IDLE_STATUS;

int connectedToWifi(
  const char* ssid, 
  const char* password, 
  AnimationCallback wifiSearchingAnimation, 
  AnimationCallback wifiConnectedAnimation, 
  AnimationCallback wifiNotConnectedAnimation
){
  //Check for Wifi module
  if(WiFi.status() == WL_NO_MODULE){
    Serial.println("Communication with Wifi Module failed.");

    //don't contunue
    if(wifiNotConnectedAnimation) {
      wifiNotConnectedAnimation(); // trigger the animation
    }

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
    Serial.print(ssid);
    Serial.println("\n");

    if(wifiSearchingAnimation) {
      wifiSearchingAnimation(); //trigger the animation
    }

    status = WiFi.begin(ssid, password);

    // wait 10 seconds for connection:
    delay(10000);
  }

  if(status == WL_CONNECTED){
    Serial.print("Succsselfully connected to WPA SSID: ");
    Serial.println(ssid);

    if(wifiConnectedAnimation){
      wifiConnectedAnimation(); //trigger the animation
    }
  } 
  else{
    Serial.print("Failed to connect to WPA SSID: ");
    Serial.println(ssid);
  }

  return status;
}