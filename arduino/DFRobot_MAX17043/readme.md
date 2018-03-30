# DFRobot_MAX17043 Gravity：Lipo Battery Management Module

The MAX17043 is ultra-compact, low-cost,host-side fuel-gauge systems 
for lithium-ion (Li+) batter-ies in handheld and portable equipment.

## DFRobot_MAX17043 Library for Arduino
---------------------------------------------------------
Provides an Arduino library for reading and interpreting MAX17043 data over I2C.

## Table of Contents

* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

<snippet>
<content>

## Installation

To use this library download the zip file, uncompress it to a folder named DFRobot_MAX17043 in Arduino library.

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
int begin();

/*
 * @brief read battery voltage in mv
 *
 * @return voltage in mv
 */
float readVoltage();

/*
 * @brief read battery voltage in precentage
 *
 * @return voltage in precentage
 */
float readPrecentage();

/*
 * @brief set MAX17043 interrput threshold
 *
 * @param pre       interrupt threshold
 */
void readVoltage(float pre);

/*
 * @brief clear MAX17043 interrupt
 *
 */
void celarInterrupt();

/*
 * @brief set MAX17043 in sleep mode
 *
 */
void setSleep();

/*
 * @brief weak up MAX17043
 *
 */
void setWeakUp();

```

## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
FireBeetle-ESP32  |      √       |             |            | 
FireBeetle-ESP8266  |      √       |             |            | 
Arduino uno |       √      |             |            | 

## History

- Jan 30, 2018 - Version 1.0 released.

## Credits

Written by DFRobot, 2018. (Welcome to our [website](https://www.dfrobot.com/))
