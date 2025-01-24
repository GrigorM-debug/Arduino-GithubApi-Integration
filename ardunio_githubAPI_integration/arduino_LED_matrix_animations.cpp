#include "arduino_LED_matrix_animations.h"
//#include "led_matrix_frames.h"

ArduinoLEDMatrix matrix;

//Wifi searching animation
void wifiSearchingAnimation(){
  matrix.loadSequence(LEDMATRIX_ANIMATION_WIFI_SEARCH);
  matrix.begin();
  matrix.play(true);
}

//Connected to Wifi animation
void wifiConnectedAnimation(){
  matrix.loadFrame(LEDMATRIX_EMOJI_HAPPY);
  matrix.begin();
  delay(3000);
}

//Connection to Wifi failed animation
void wifiNotConnectedAnimation(){
  matrix.loadFrame(LEDMATRIX_EMOJI_SAD);
  matrix.begin();
  delay(3000);
}


