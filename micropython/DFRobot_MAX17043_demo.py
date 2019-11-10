import time
from machine import I2C, Pin
from DFRobot_MAX17043 import DFRobot_MAX17043

# Get I2C bus
i2c = I2C(scl = Pin(22), sda = Pin(21), freq=400000)

gauge = DFRobot_MAX17043(i2c)

def interruptCallBack(channel):
  gauge.clearInterrupt()
  print('Low power alert interrupt!')
  #put your battery low power alert interrupt service routine here

pin_irq = Pin(25, Pin.IN)
pin_irq.irq(trigger = Pin.IRQ_FALLING, handler = interruptCallBack)

rslt = gauge.begin()

while rslt != 0:
  print('gauge begin faild')
  time.sleep(2)
  rslt = gauge.begin()

#gauge.setInterrupt(32) #use this to modify alert threshold as 1% - 32% (integer)
print('gauge begin successful')

while True:
  time.sleep(2)
  print('voltage: ' + str(gauge.readVoltage()) + 'mV')
  print('percentage: ' + str(round(gauge.readPercentage(), 2)) + '%')
