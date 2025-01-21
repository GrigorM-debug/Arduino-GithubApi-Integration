#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_H

#include <Arduino.h>
#include <WiFiS3.h>
#include <functional>

using AnimationCallback = std::function<void()>;

int connectedToWifi(
        const char* ssid, 
        const char* password, 
        AnimationCallback wifiSearchingAnimation = nullptr, 
        AnimationCallback wifiConnectedAnimation = nullptr, 
        AnimationCallback wifiNotConnectedAnimation = nullptr);

#endif