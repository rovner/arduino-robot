#ifndef ARDUINO_MOTIONCONTROLLER_H
#define ARDUINO_MOTIONCONTROLLER_H

#include "MotorController.h"

class MotionController {
public:
    MotionController(MotorController *leftMotor, MotorController *rightMotor);

    void switchModeIfNeeded(unsigned long code);

private:
    void moveForward();

    void moveBackward();

    void moveLeft();

    void moveRight();

    void stop();

    void increaseSpeed();

    void decreaseSpeed();

    MotorController *leftMotor;
    MotorController *rightMotor;
};


#endif //ARDUINO_MOTIONCONTROLLER_H
