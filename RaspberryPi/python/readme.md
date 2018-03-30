# DFRobot_MAX17043 Gravity：Lipo Battery Management Module

The MAX17043 is ultra-compact, low-cost,host-side fuel-gauge systems 
for lithium-ion (Li+) batter-ies in handheld and portable equipment.

## DFRobot_MCP4725.py Library for Raspberry pi
---------------------------------------------------------
Provides an Raspberry pi library for reading and interpreting MAX17043 data over I2C.

## Table of Contents

* [Installation](#installation)
* [Methods](#methods)
<snippet>
<content>

## Installation

Download and install smbus library on Raspberry pi. Steps to install smbus are provided at:

$> sudo apt-get install -y python-smbus
$> sudo apt-get install -y i2c-tools

Run the program:

```cpp
 
$> python DFRobot_MAX17043.py

```

Run the demo:

```cpp

$> cd readAndInt
$> python readAndInt.py

```
## Methods

```C++

/*
 * @brief create MAX17043 object
 *
 * @return MAX17043 object
 */
DFRobot_MAX17043();

/*
 * @brief MAX17043 begin and test moudle
 *
 * @return MAX17043 object
 */
def begin();

/*
 * @brief read battery voltage in mv
 *
 * @return voltage in mv
 */
def readVoltage();

/*
 * @brief read battery voltage in precentage
 *
 * @return voltage in precentage
 */
def readPrecentage();

/*
 * @brief set MAX17043 interrput threshold
 *
 * @param pre       interrupt threshold
 */
def readVoltage(float pre);

/*
 * @brief clear MAX17043 interrupt
 *
 */
def celarInterrupt();

/*
 * @brief set MAX17043 in sleep mode
 *
 */
def setSleep();

/*
 * @brief weak up MAX17043
 *
 */
def setWeakUp();

```

## Credits

Written by DFRobot, 2018. (Welcome to our [website](https://www.dfrobot.com/))

