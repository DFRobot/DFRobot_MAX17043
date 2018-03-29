import import smbus
import time
import datetime

# Get I2C bus
bus = smbus.SMBus(1)

MAX17043_ADDR = 0x36
MAX17043_VCELL = 0x02
MAX17043_SOC = 0x04
MAX17043_MODE = 0x06
MAX17043_VERSION = 0x08
MAX17043_CONFIG = 0x0c
MAX17043_COMMAND = 0xfe

class DFRobot_MAX17043():
  
  def __init__(self):
    pass
  
  def begin(self):
    self.write16(MAX17043_COMMAND, 0x5400)
    time.sleep(0.01)
    if self.read16(MAX17043_CONFIG) is 0x971c:
      self.write16(MAX17043_MODE, 0x4000)
      self.write16(MAX17043_CONFIG, 0x9700)
      return 0
    else
      return -1
      
  def readVoltage(self):
    return (1.25 * (self.read16(MAX17043_VCELL) >> 4))
  
  def readPrecentage(self):
    tmp = self.read16(MAX17043_SOC)
    return ((tmp >> 8) + 0.003906 * (tmp & 0x00ff))

  def setInterruptPrecentage(self, pre):
    if pre > 32:
      pre = 32
    else if pre < 1:
      pre = 1
    pre = 32 - pre
    self.writeRegBits(MAX17043_CONFIG, pre, 0x01f, 0)

  def clearInterrupt(self):
    self.writeRegBits(MAX17043_CONFIG, 0, 0x01, 5)
    
  def setSleep(self):
    self.writeRegBits(MAX17043_CONFIG, 1, 0x01, 7)
    
  def setWakeUp(self):
    self.writeRegBits(MAX17043_CONFIG, 0, 0x01, 7)
  
  def write16(self, reg, dat):
    buf = [dat >> 8, dat & 0x00ff]
    bus.write_block_data(self.addr, reg, buf)
    
  def read16(self, reg):
    buf = bus.read_i2c_block_data(self.addr, reg, 2)
    return ((buf[0] << 8) | buf[1])
  
  def writeRegBits(self, reg, dat, bits, offset):
    tmp = self.read16(reg)
    tmp = (tmp & (~(bits << offset))) | (dat << offset)
    self.write16(reg, tmp)
  