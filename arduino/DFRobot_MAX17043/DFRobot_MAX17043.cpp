#include "DFRobot_MAX17043.h"

DFRobot_MAX17043::DFRobot_MAX17043() {}

int DFRobot_MAX17043::begin()
{
  // write16(MAX17043_COMMAND, 0x0054);  //power on reset
  write16(MAX17043_COMMAND, 0x5400);  //power on reset
  delay(10);
  _DBG_CODE(Serial.print("\nbegin: "));
  _DBG_CODE(Serial.println(read16(MAX17043_CONFIG), HEX));
  if(read16(MAX17043_CONFIG) == 0x971c) {  //default 0x971c
    write16(MAX17043_MODE, 0x4000);  //quick start
    write16(MAX17043_CONFIG, 0x9700);
    _DBG_CODE(Serial.println(read16(MAX17043_CONFIG), HEX));
    delay(10);
    return 0;
  }
  return -1;
}

float DFRobot_MAX17043::readVoltage()
{
  return (1.25f * (float)(read16(MAX17043_VCELL) >> 4));
}

float DFRobot_MAX17043::readPrecentage()
{
  uint16_t        pre = read16(MAX17043_SOC);
  return (float)((pre >> 8) + 0.003906f * (pre & 0x00ff));
}

void DFRobot_MAX17043::setInterruptPrecentage(float pre)
{
  uint16_t        temp;
  if(pre > 32.0f)
    temp = 32;
  else if(pre < 1.0f)
    temp = 1;
  else
    temp = (uint16_t)pre;
  temp = 32 - temp;
  writeRegBits(MAX17043_CONFIG, temp, 0x01f, 0);
}

void DFRobot_MAX17043::clearInterrupt()
{
  writeRegBits(MAX17043_CONFIG, 0, 0x01, 5);
}

void DFRobot_MAX17043::setSleep()
{
  writeRegBits(MAX17043_CONFIG, 1, 0x01, 7);
}

void DFRobot_MAX17043::setWakeUp()
{
  writeRegBits(MAX17043_CONFIG, 0, 0x01, 7);
}
