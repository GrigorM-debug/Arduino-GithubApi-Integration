#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_H

#include <Arduino.h>
#include <WiFiS3.h>
#include <functional>
using namespace std;

using AnimationCallback = function<void()>;

int connectedToWifi(
        const char* ssid, 
        const char* password, 
        AnimationCallback wifiSearchingAnimation = nullptr, 
        AnimationCallback wifiConnectedAnimation = nullptr, 
        AnimationCallback wifiNotConnectedAnimation = nullptr);

void printMacAddress(byte mac[]);

void printCurrentConnectedNetworkData();


#endif