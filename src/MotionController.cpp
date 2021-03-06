#include <Arduino.h>
#include "MotionController.h"
#include "MotorController.h"
#include "RemoteControl.h"

MotionController::MotionController(MotorController *leftMotor, MotorController *rightMotor) {
    MotionController::leftMotor = leftMotor;
    MotionController::rightMotor = rightMotor;
}

void MotionController::switchModeIfNeeded(unsigned long code) {
    switch (code) {
        case PLUS:
            moveForward();
            break;
        case MINUS:
            moveBackward();
            break;
        case PREV:
            moveLeft();
            break;
        case NEXT:
            moveRight();
            break;
        case MENU:
            increaseSpeed();
            delay(50);
            break;
        case BACK:
            decreaseSpeed();
            delay(50);
            break;
        case REPEAT:
            //do nothing
            break;
        default:
            stop();
    }
}

void MotionController::moveForward() {
    leftMotor->moveForward();
    rightMotor->moveForward();
}

void MotionController::moveBackward() {
    leftMotor->moveBackward();
    rightMotor->moveBackward();
}

void MotionController::moveLeft() {
    leftMotor->moveBackward();
    rightMotor->moveForward();
}

void MotionController::moveRight() {
    leftMotor->moveForward();
    rightMotor->moveBackward();
}

void MotionController::stop() {
    leftMotor->stop();
    rightMotor->stop();
}

void MotionController::increaseSpeed() {
    leftMotor->increaseSpeed();
    rightMotor->increaseSpeed();
}

void MotionController::decreaseSpeed() {
    leftMotor->decreaseSpeed();
    rightMotor->decreaseSpeed();
}

void MotionController::init() {
    leftMotor->init();
    rightMotor->init();
}