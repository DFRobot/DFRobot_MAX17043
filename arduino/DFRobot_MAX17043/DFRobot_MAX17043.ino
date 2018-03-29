/*
 * file DFRobot_MAX17043.ino
 *
 * connect lipo I2C interface with your board (please reference board compatibility)
 * 
 * Voltage, precentage will be printed via serial.
 * Use API to config alaram and sleep (please reference to the readme in lib)
 *
 * Copyright   [DFRobot](http://www.dfrobot.com), 2016
 * Copyright   GNU Lesser General Public License
 *
 * version  V1.0
 * date  2018-3-26
 */

#include "DFRobot_MAX17043.h"
#include "Wire.h"

DFRobot_MAX17043        lipo;

void interruptCallBack() {
  lipo.clearInterrupt();
  Serial.println("lipo interrupt call back");
}

void setup() {
  Serial.begin(115200);
  while(!Serial);
  while(lipo.begin() != 0) {
    Serial.println("lipo begin faild!");
    delay(2000);
  }
  Serial.println("lipo begin successful!");
  pinMode(2, INPUT);
  attachInterrupt(2, interruptCallBack, LOW);  //default alaram is 32%
}

void loop() {
  delay(1000);
  Serial.println();

  Serial.print("voltage: ");
  Serial.print(lipo.readVoltage());
  Serial.println(" mv");

  Serial.print("precentage: ");
  Serial.print(lipo.readPrecentage());
  Serial.println(" %");
}
