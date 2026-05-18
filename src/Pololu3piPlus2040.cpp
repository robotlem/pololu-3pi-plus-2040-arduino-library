//
// Created by robo on 17.05.26.
//

#include "Pololu3piPlus2040.h"


uint16_t Pololu3piPlus2040::readBatteryMillivolts()
{
    // Pin 26 is shared with the down emitter. The code in the LineSensors class will reconfigure to SIO mode
    // every time it is used to enable or disable the emitter.
    const uint32_t batteryVoltagePin = 26;
    const uint32_t sampleCount = 10;
    uint32_t sum = 0;
    for (uint32_t i = 0; i < sampleCount; i++)
    {
        sum += analogRead(batteryVoltagePin);
    }

    // The voltage divider steps the voltage down by 1/11th of the actual battery voltage.
    // The analogRead readings fall in a 10-bit range.
    return (3300 * sum * 11 + sampleCount * 511) / (sampleCount * 1023);
}

