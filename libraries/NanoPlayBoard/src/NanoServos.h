/*
  NanoServos.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 18, 2016.
  Released under GNU GPL v3.
*/

#ifndef NanoServos_h
#define NanoServos_h

#include "Arduino.h"
#include "NanoServo.h"

#define STOP 90
#define MAX_SPEED_LEFT_FORWARD 0
#define MAX_SPEED_LEFT_BACKWARD 180
#define MAX_SPEED_RIGHT_FORWARD 180
#define MAX_SPEED_RIGHT_BACKWARD 0

class NanoServos
{
  public:
    NanoServos();
    NanoServos(uint8_t pin_right, uint8_t pin_left);
    void goForward(uint32_t milliseconds);
    void goBackward(uint32_t milliseconds);
    void goRight(uint32_t milliseconds);
    void goLeft(uint32_t milliseconds);
    void goForward();
    void goBackward();
    void goRight();
    void goLeft();
    void stop();
    void setSpeed(uint8_t speed);

  private:
    NanoServo _servo_right;
    NanoServo _servo_left;
    uint8_t _left_forward;
    uint8_t _left_backward;
    uint8_t _right_forward;
    uint8_t _right_backward;
};

#endif
