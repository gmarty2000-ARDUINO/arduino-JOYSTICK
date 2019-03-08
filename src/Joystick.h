#ifndef __JOYSTICK_h
#define __JOYSTICK_h

#include "Arduino.h"

class Joystick {
    public:     Joystick(int, int, int);
                void printX(String, int, int);
                void printY(String, int, int);
                void printZ(String);
                void print(String, String, String, int, int);
                String toString();
    private:    int pinX;
                int pinY;
                int pinZ;
};

#endif
