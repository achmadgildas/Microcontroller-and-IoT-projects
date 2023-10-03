/*
  Register.h - Library for the Arduino Nano PlayBoard
  Created by Antonio Morales, June, 2016.
  Released under GNU GPL v3.
*/

#ifndef Register_h
#define Register_h

#include "Arduino.h"

class Register
{
  public:
    Register();
    Register(uint8_t data_in, uint8_t clock_in, uint8_t clock_out);
    void clear();
    void write(byte data);

  private:
    uint8_t _data_in;
    uint8_t _clock_in;
    uint8_t _clock_out;
    unsigned long _period;
    unsigned int _baudrate;
};

#endif