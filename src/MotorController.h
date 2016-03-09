//
// Created by Vyacheslav Rovnyakov on 09/03/16.
//

#ifndef ARDUINO_MOTORCONTROLLER_H
#define ARDUINO_MOTORCONTROLLER_H

class MotorController {
public:
    MotorController(int forwardLedPin, int backwardLedPin);

    void moveForward();

    void moveBackward();

    void stop();

private:
    int forwardLedPin;
    int backwardLedPin;

    void initIfNeeded();

    bool initialized = false;
};

#endif //ARDUINO_MOTORCONTROLLER_H
