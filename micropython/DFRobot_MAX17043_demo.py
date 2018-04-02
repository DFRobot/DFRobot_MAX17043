import time
from machine import Pin
from DFRobot_MAX17043 import DFRobot_MAX17043

gauge = DFRobot_MAX17043()

def interruptCallBack(channel):
  gauge.clearInterrupt()
  print('MAX17043 interrupt callback')
  #put your battery low power alert interrupt service routine here

pin_irq = Pin(25, Pin.IN)
pin_irq.irq(trigger = Pin.IRQ_FALLING, handler = interruptCallBack)

rslt = gauge.begin()

while rslt != 0:
  print('gauge begin faild')
  time.sleep(2)
  rslt = gauge.begin()

#gauge.setInterrupt(32) #use this to modify alaram threshold as 1% - 32% (integer)
print('gauge begin successful')

while True:
  time.sleep(2)
  print('read voltage: ' + str(gauge.readVoltage()) + 'mV')
  print('read percentage: ' + str(round(gauge.readPercentage(), 2)) + '%')
