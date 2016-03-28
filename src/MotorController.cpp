#include "MotorController.h"
#include <Arduino.h>

MotorController::MotorController(int forwardPin, int backwardPin, int controlPin) {
    MotorController::forwardPin = forwardPin;
    MotorController::backwardPin = backwardPin;
    MotorController::controlPin = controlPin;
}

void MotorController::moveForward() {
    initIfNeeded();
    stop();
    analogWrite(controlPin, 0);
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, HIGH);
    analogWrite(controlPin, 200);
}

void MotorController::moveBackward() {
    initIfNeeded();
    analogWrite(controlPin, 0);
    digitalWrite(forwardPin, HIGH);
    digitalWrite(backwardPin, LOW);
    analogWrite(controlPin, 200);
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