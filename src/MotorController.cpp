#include "MotorController.h"
#include <Arduino.h>

MotorController::MotorController(int forwardLedPin, int backwardLedPin) {
    MotorController::forwardLedPin = forwardLedPin;
    MotorController::backwardLedPin = backwardLedPin;
}

void MotorController::moveForward() {
    initIfNeeded();
    digitalWrite(forwardLedPin, HIGH);
    digitalWrite(backwardLedPin, LOW);
}

void MotorController::moveBackward() {
    initIfNeeded();
    digitalWrite(backwardLedPin, HIGH);
    digitalWrite(forwardLedPin, LOW);
}

void MotorController::stop() {
    initIfNeeded();
    digitalWrite(forwardLedPin, LOW);
    digitalWrite(backwardLedPin, LOW);
}

void MotorController::initIfNeeded() {
    if (!initialized) {
        pinMode(forwardLedPin, OUTPUT);
        pinMode(backwardLedPin, OUTPUT);
        initialized = true;
    }
}