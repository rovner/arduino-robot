#include "MotorController.h"
#include <Arduino.h>

MotorController::MotorController(uint8_t forwardPin, uint8_t backwardPin, uint8_t controlPin) {
    MotorController::forwardPin = forwardPin;
    MotorController::backwardPin = backwardPin;
    MotorController::controlPin = controlPin;
    MotorController::speed = 10;
}

void MotorController::moveForward() {
    analogWrite(controlPin, 0);
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, HIGH);
    analogWrite(controlPin, getSpeed());
}

void MotorController::moveBackward() {
    analogWrite(controlPin, 0);
    digitalWrite(forwardPin, HIGH);
    digitalWrite(backwardPin, LOW);
    analogWrite(controlPin, getSpeed());
}

void MotorController::stop() {
    analogWrite(controlPin, 0);
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, LOW);
}

void MotorController::init() {
    pinMode(forwardPin, OUTPUT);
    pinMode(backwardPin, OUTPUT);
    pinMode(controlPin, OUTPUT);
}

void MotorController::increaseSpeed() {
    setSpeed(speed + 1);
}

void MotorController::decreaseSpeed() {
    setSpeed(speed - 1);
}

void MotorController::setSpeed(uint8_t speed) {
    if (speed > 0 && speed <= 10) {
        MotorController::speed = speed;
    }
}

int MotorController::getSpeed() {
    return 50 + speed * 20;
}
