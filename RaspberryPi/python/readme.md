# DFRobot_MAX17043 Gravity：Lipo Battery Management Module

The MAX17043 is ultra-compact, low-cost,host-side fuel-gauge systems 
for lithium-ion (Li+) batter-ies in handheld and portable equipment.

## DFRobot_MAX17043.py Library for Raspberry pi
---------------------------------------------------------
Provides an Raspberry pi library for reading and interperting MAX17043 data over I2C.

## Table of Contents

* [Installation](#installation)
* [Methods](#methods)

## Installation

Download and install smbus library on Raspberry pi. Steps to install smbus are provided at:

$> sudo apt-get install -y python-smbus <br>
$> sudo apt-get install -y i2c-tools

Run the program:

$> python DFRobot_MAX17043.py

Run the demo:

$> cd readAndInt.py <br>
$> python readAndInt.py

## Methods

```python

#
 # @brief create MAX17043 object
 #
 # @return MAX17043 object
#
DFRobot_MAX17043();

#
 # @brief MAX17043 begin and test moudle
 #
 # @return result:        0: successful
 #                       -1: faild
#
def begin();

#
 # @brief read battery voltage in mV
 #
 # @return voltage in mV
#
def readVoltage();

'''
 # @brief read battery voltage in percentage
 #
 # @return voltage in percentage
'''
def readPercentage();

'''
 # @brief set MAX17043 interrput threshold
 #
 # @param per       interrupt threshold as %1 - %32 (integer)
'''
def setInterrupt(per);

'''
 # @brief clear MAX17043 interrupt
 # 
'''
def clearInterrupt();

'''
 # @brief set MAX17043 in sleep mode
 # 
'''
def setSleep();

'''
 # @brief weak up MAX17043
 # 
'''
def setWeakUp();

```

## Credits

Written by DFRobot, 2018. (Welcome to our [website](https://www.dfrobot.com/))
