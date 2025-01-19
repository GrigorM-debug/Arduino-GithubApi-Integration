#include <Wire.h>
#include "i2c_device_scanner.h"
#include <LiquidCrystal_I2C.h>
#include "Arduino_LED_Matrix.h"
#include "led_matrix_frames.h"

ArduinoLEDMatrix matrix;

const uint32_t happy[] = {
    0x19819,
    0x80000001,
    0x81f8000
};

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  
  matrix.loadSequence(frames);
  matrix.begin();

  //matrix.loadFrame(LEDMATRIX_LIKE);

  matrix.play(true);

  byte i2cDeviceAddress = scanI2CDevices();

  if(i2cDeviceAddress > 0){
    LiquidCrystal_I2C lcd(i2cDeviceAddress, 20, 4);

    lcd.init();
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print(i2cDeviceAddress, HEX);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
