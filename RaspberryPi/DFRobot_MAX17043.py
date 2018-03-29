import import smbus
import time
import datetime

# Get I2C bus
bus = smbus.SMBus(1)

class DFRobot_MAX17043():
  
  def __init__(self):
    self.addr = 0x36
    self.REG_VCELL = 0x02
    self.REG_SOC = 0x04
    self.REG_MODE = 0x06
    self.REG_VERSION = 0x08
    self.REG_CONFIG = 0x0c
    self.REG_COMMAND = 0xfe
  
  def begin(self):
    pass
    
  def write16(self, reg, dat):
    buf = [dat >> 8, dat & 0x00ff]
    bus.write_block_data(self.addr, reg, buf)
    
  def read16(self, reg):
    buf = bus.read_i2c_block_data(self.addr, reg, 2)
    return ((buf[0] << 8) | buf[1])
