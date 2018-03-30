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

#ifdef __AVR__
  #define ALT_PIN       2
#else
  #define ALT_PIN       D2
#endif

DFRobot_MAX17043        lipo;
uint8_t       intFlag = 0;

void interruptCallBack()
{
  intFlag = 1;
}

void setup()
{
  Serial.begin(115200);
  while(!Serial);
  Serial.println();
  Serial.println();
  pinMode(ALT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ALT_PIN), interruptCallBack, FALLING);  //default alaram is 32%
  
  while(lipo.begin() != 0) {
    Serial.println("lipo begin faild!");
    delay(2000);
  }
  delay(2);
  Serial.println("lipo begin successful!");
}

void loop()
{
  delay(2000);
  Serial.println();

  Serial.print("voltage: ");
  Serial.print(lipo.readVoltage());
  Serial.println(" mV");

  Serial.print("precentage: ");
  Serial.print(lipo.readPrecentage());
  Serial.println(" %");

  if(intFlag == 1) {
    lipo.clearInterrupt();
    Serial.println("lipo interrupt call back");
    intFlag = 0;
  }
}
