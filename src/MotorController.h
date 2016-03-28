//
// Created by Vyacheslav Rovnyakov on 09/03/16.
//

#ifndef ARDUINO_MOTORCONTROLLER_H
#define ARDUINO_MOTORCONTROLLER_H

class MotorController {
public:
    MotorController(int forwardPin, int backwardPin, int controlPin);

    void moveForward();

    void moveBackward();

    void stop();

    void increaseSpeed();

    void decreaseSpeed();

private:
    int forwardPin;
    int backwardPin;
    int controlPin;
    int speed;

    void initIfNeeded();

    void setSpeed(int speed);

    int getSpeed();

    bool initialized = false;
};

#endif //ARDUINO_MOTORCONTROLLER_H
