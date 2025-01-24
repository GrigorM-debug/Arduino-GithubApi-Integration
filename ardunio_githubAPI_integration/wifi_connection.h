#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_H

#include <Arduino.h>
#include <WiFiS3.h>
#include <functional>

int connectedToWifi(
        const char* ssid, 
        const char* password
      );

void printMacAddress(byte mac[]);

void printCurrentConnectedNetworkData();

void printArduinoBoardWifiData();

#endif