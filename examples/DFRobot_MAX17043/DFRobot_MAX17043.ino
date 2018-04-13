/*
 * file DFRobot_MAX17043.ino
 *
 *  The MAX17043 is ultra-compact, low-cost,host-side fuel-gauge systems for lithium-ion (Li+) batter-ies in handheld and portable 
 *equpiment.It employs Gravity I2C interface,ultra-low opearting current, and real-time tracking of the relative state of charge 
 *(SOC) of the battery through Maxim's patented algorithm,eliminating the need for full-to-empty relearning and offset accumualtion 
 *errors.Plug and play to accurately measure the voltage and remaining power of the battery. The module  also features as a low 
 *battery power alert interrupt function.  When the battery power falls below specified threshold, the ALR pin generates a falling 
 *pluse to trigger the external interrupt of the controller.One thing should mention that the default value of the battery low power
 *interrupt alert threshold is 32%, this threshold can be set by the function setInterrupt().
 * 
 * Voltage, percentage will be printed via serial.
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
  #define ALR_PIN       2
#else
  #define ALR_PIN       D2
#endif

#define PRINT_INTERVAL        2000

DFRobot_MAX17043        gauge;
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
  pinMode(ALR_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ALR_PIN), interruptCallBack, FALLING);  //default alert is 32%
  
  while(gauge.begin() != 0) {
    Serial.println("gauge begin faild!");
    delay(2000);
  }
  delay(2);
  Serial.println("gauge begin successful!");
  //gauge.setInterrupt(32);  //use this to modify alert threshold as 1% - 32% (integer)
}

void loop()
{
  static unsigned long lastMillis = 0;
  if((millis() - lastMillis) > PRINT_INTERVAL) {
    lastMillis = millis();
    Serial.println();

    Serial.print("voltage: ");
    Serial.print(gauge.readVoltage());
    Serial.println(" mV");

    Serial.print("precentage: ");
    Serial.print(gauge.readPercentage());
    Serial.println(" %");
  }

  if(intFlag == 1) {
    intFlag = 0;
    gauge.clearInterrupt();
    Serial.println("Low power alert interrupt!");
    //put your battery low power alert interrupt service routine here
  }
}
