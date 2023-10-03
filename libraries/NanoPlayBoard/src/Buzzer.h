/*
  Buzzer.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released under GNU GPL v3.
*/

#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"

class Buzzer
{
  public:
    Buzzer();
    Buzzer(uint8_t pin);
    void playTone(unsigned int frequency);
    void playTone(unsigned int frequency, unsigned long duration);
    void stopTone();

  private:
    uint8_t _pin;
};

#endif