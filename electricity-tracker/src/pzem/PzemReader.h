#ifndef PzemReader_h
#define PzemReader_h

#include <PZEM004Tv30.h>
#include <SoftwareSerial.h>
#include "./PzemReadingModel.h"

struct PzemReader
{
  String title;
  PZEM004Tv30 pzem;

  PzemReader(String title, int8_t rx, int8_t tx) : title(title)
  {
    SoftwareSerial serialA(rx, tx);
    PZEM004Tv30 innstance(serialA);
    pzem = innstance;
  }

  PzemReadingModel getRead()
  {
    PzemReadingModel reading;
    // Read the data from the sensor
    reading.title = title;
    reading.voltage = pzem.voltage();
    reading.current = pzem.current();
    reading.power = pzem.power();
    reading.energy = pzem.energy();
    reading.frequency = pzem.frequency();
    reading.pf = pzem.pf();

    return reading;
  }
};

#endif