#include "MotorController.h"
#include <Arduino.h>

MotorController::MotorController(int forwardPin, int backwardPin, int controlPin) {
    MotorController::forwardPin = forwardPin;
    MotorController::backwardPin = backwardPin;
    MotorController::controlPin = controlPin;
    MotorController::speed = 10;
}

void MotorController::moveForward() {
    initIfNeeded();
    stop();
    analogWrite(controlPin, 0);
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, HIGH);
    analogWrite(controlPin, getSpeed());
}

void MotorController::moveBackward() {
    initIfNeeded();
    analogWrite(controlPin, 0);
    digitalWrite(forwardPin, HIGH);
    digitalWrite(backwardPin, LOW);
    analogWrite(controlPin, getSpeed());
}

void MotorController::stop() {
    initIfNeeded();
    analogWrite(controlPin, 0);
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, LOW);
}

void MotorController::initIfNeeded() {
    if (!initialized) {
        pinMode(forwardPin, OUTPUT);
        pinMode(backwardPin, OUTPUT);
        pinMode(controlPin, OUTPUT);
        initialized = true;
    }
}

void MotorController::increaseSpeed() {
    setSpeed(speed + 1);
}

void MotorController::decreaseSpeed() {
    setSpeed(speed - 1);
}

void MotorController::setSpeed(int speed) {
    if (speed > 0 && speed <= 10) {
        MotorController::speed = speed;
    }
}

int MotorController::getSpeed() {
    return 50 + speed * 20;
}
