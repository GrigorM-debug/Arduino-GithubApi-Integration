#include "wifi_connection.h"
#include "arduino_LED_matrix_animations.h"

int status = WL_IDLE_STATUS;

IPAddress local_IP(192, 168, 0, 184);        // Desired static IP address within router's subnet
IPAddress gateway(192, 168, 0, 102);           // Your router's IP address
IPAddress subnet(255, 255, 255, 0);          // Subnet mask
IPAddress dns(8, 8, 8, 8);

int connectedToWifi(
  const char* ssid, 
  const char* password
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

  // Configure static IP
  WiFi.config(local_IP, dns, gateway, subnet);

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

    printCurrentConnectedNetworkData();
    printArduinoBoardWifiData();
  } 
  else{
    Serial.print("Failed to connect to WPA SSID: ");
    Serial.println(ssid);
  }

  return status;
}

void printMacAddress(byte mac[]){
  for(int i = 0; i < 6; i++){
    if(i > 0){
      Serial.print(":");
    }

    if(mac[i] < 6){
      Serial.print("0");
    }

    Serial.print(mac[i], HEX);
  }

  Serial.println();
}

void printCurrentConnectedNetworkData(){
  Serial.println("Current Connected Network Data: ");

  //Print current connected network SSID
  Serial.print("  SSID: ");
  Serial.println(WiFi.SSID());

  //Print current connected network MAC Address
  byte bssid[6];
  WiFi.BSSID(bssid);
  Serial.print("  BSSID: ");
  printMacAddress(bssid);

  //Print the connection signal strength
  long rssi = WiFi.RSSI();
  Serial.print("  Signal strength (RSSI): ");
  Serial.println(rssi);

  //Print the encryption type
  byte encryption = WiFi.encryptionType();
  Serial.print("  Encryption type: ");
  Serial.println(encryption, HEX);
  Serial.println();
}

void printArduinoBoardWifiData(){
  IPAddress ip = WiFi.localIP();
  Serial.print("To see this page in action open this link: http://");
  Serial.println(ip);
}
