import sys
sys.path.append('../')
import time

from DFRobot_MAX17043 import *
import RPi.GPIO as GPIO

lipo = DFRobot_MAX17043()

GPIO.setMode(GPIO.BOARD)
GPIO.setup(7, GPIO.IN)

def interruptCallBack():
  global lipo
  lipo.clearInterrupt()
  print('gpio interruptCallBack')
  
GPIO.add_event_detect(7, GPIO.FALLING, callback = interruptCallBack, 5)

rslt = lipo.begin()

while rslt != 0:
  print('lipo begin faild')
  time.sleep(2)
  rslt = lipo.begin()

print('lipo config ' + lipo.read16())
  
while True:
  time.sleep(1)
  print('read voltage: ' + lipo.readVoltage() + 'mv')
  print('read precentage: ' + lipo.readPrecentage() + '%')
