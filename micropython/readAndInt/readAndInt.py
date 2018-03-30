import sys
sys.path.append('../')
import time

from DFRobot_MAX17043 import DFRobot_MAX17043
import RPi.GPIO as GPIO

lipo = DFRobot_MAX17043()

GPIO.setmode(GPIO.BOARD)
GPIO.setup(7, GPIO.IN)

def interruptCallBack(channel):
  global lipo
  lipo.clearInterrupt()
  print('gpio interruptCallBack')
  
GPIO.add_event_detect(7, GPIO.FALLING, callback = interruptCallBack, bouncetime = 5)

rslt = lipo.begin()

while rslt != 0:
  print('lipo begin faild')
  time.sleep(2)
  rslt = lipo.begin()

print('lipo begin successful')
print('lipo config ' + str(hex(lipo.read16(0x0c))))
  
while True:
  time.sleep(2)
  print('read voltage: ' + str(lipo.readVoltage()) + 'mv')
  print('read precentage: ' + str(lipo.readPrecentage()) + '%')
