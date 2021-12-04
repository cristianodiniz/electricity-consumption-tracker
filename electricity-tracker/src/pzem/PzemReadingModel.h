#ifndef PzemReadingModel_h
#define PzemReadingModel_h

#include "Arduino.h"

struct PzemReadingModel
{
    String title;
    float voltage;
    float current;
    float power;
    float energy;
    float frequency;
    float pf;
    boolean isNotValid()
    {
        return (isnan(voltage) || isnan(current) || isnan(power) || isnan(energy) || isnan(frequency) || isnan(pf));
    }
    String voltageFormated()
    {
        return "Voltage  : " + String(voltage, 2) + "V";
    }
    String currentFormated()
    {
        return "Current  : " + String(current, 2) + "A";
    }
    String powerFormated()
    {
        return "Power    : " + String(power, 2) + "W";
    }
    String energyFormated()
    {
        return "Energy   : " + String(energy, 3) + "kWh";
    }
    String frequencyFormated()
    {
        return "Frequency: " + String(frequency, 1) + "Hz";
    }
    String pfFormated()
    {
        return "PF       : " + String(pf, 2);
    }
};

#endif