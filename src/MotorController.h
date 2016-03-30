//
// Created by Vyacheslav Rovnyakov on 09/03/16.
//

#ifndef ARDUINO_MOTORCONTROLLER_H
#define ARDUINO_MOTORCONTROLLER_H

#include <Arduino.h>

class MotorController {
public:
    MotorController(uint8_t forwardPin, uint8_t backwardPin, uint8_t controlPin);

    void moveForward();

    void moveBackward();

    void stop();

    void increaseSpeed();

    void decreaseSpeed();

    void init();

private:
    uint8_t forwardPin;
    uint8_t backwardPin;
    uint8_t controlPin;
    uint8_t speed;

    void setSpeed(uint8_t speed);

    int getSpeed();
};

#endif //ARDUINO_MOTORCONTROLLER_H
