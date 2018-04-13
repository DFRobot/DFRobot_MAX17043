#ifndef __DFROBOT_MAX17043_H
#define __DFROBOT_MAX17043_H

#include "Arduino.h"
#include "Wire.h"

#define _DBG        0

#if(_DBG)
  #define _DBG_CODE(x)      x
#else
  #define _DBG_CODE(x)
#endif

#define MAX17043_ADDRESS        0x36

#define MAX17043_VCELL          0x02
#define MAX17043_SOC            0x04
#define MAX17043_MODE           0x06
#define MAX17043_VERSION        0x08
#define MAX17043_CONFIG         0x0c
#define MAX17043_COMMAND        0xfe

class DFRobot_MAX17043 {
  public:
    DFRobot_MAX17043();

    int         begin();
    float       readVoltage();
    float       readPercentage();
    void        setInterrupt(uint8_t per);
    void        clearInterrupt();
    void        setSleep();
    void        setWakeUp();

  private:
    //!!!     little ending
    void write16(uint8_t reg, uint16_t dat) {
      Wire.begin();
      Wire.beginTransmission(MAX17043_ADDRESS);
      Wire.write(reg);
      Wire.write(dat >> 8);
      Wire.write(dat);
      Wire.endTransmission();
    }

    uint16_t read16(uint8_t reg) {
      uint16_t        temp;
      Wire.begin();
      Wire.beginTransmission(MAX17043_ADDRESS);
      Wire.write(reg);
      Wire.endTransmission();
      Wire.requestFrom(MAX17043_ADDRESS, 2);
      temp = (uint16_t)Wire.read() << 8;
      temp |= (uint16_t)Wire.read();
      Wire.endTransmission();
      return temp;
    }

    void writeRegBits(uint8_t reg, uint16_t dat, uint16_t bits, uint8_t offset) {
      uint16_t        temp;
      temp = read16(reg);
      temp = (temp & (~(bits << offset))) | (dat << offset);
      write16(reg, temp);
    }
};

#endif
