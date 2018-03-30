import sys
import timefrom machine import Pin
from DFRobot_MAX17043 import DFRobot_MAX17043

lipo = DFRobot_MAX17043()

def interruptCallBack(channel):
  global lipo
  lipo.clearInterrupt()
  print('gpio interruptCallBack')
  pin_irq = Pin(25, Pin.IN)pin_irq.irq(trigger = Pin.IRQ_FALLING, handler = interruptCallBack)

rslt = lipo.begin()

while rslt != 0:
  print('lipo begin faild')
  time.sleep(2)
  rslt = lipo.begin()

print('lipo begin successful')

while True:
  time.sleep(2)
  print('read voltage: ' + str(lipo.readVoltage()) + 'mv')
  print('read precentage: ' + str(lipo.readPrecentage()) + '%')

