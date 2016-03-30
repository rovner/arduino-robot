#include <Arduino.h>
#include "RemoteControl.h"
#include "PowerController.h"
#include "MotorController.h"
#include "MotionController.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
RemoteControl rc(11);
PowerController power;
MotorController left(MotorController(8, 9, 10));
MotorController right(MotorController(4, 5, 6));
MotionController motion(&left, &right);

void setup() {
    Serial.begin(9600);
    motion.init();
    rc.init();
}

void loop() {
    unsigned long code = rc.getIRCode();
    power.switchModeIfNeeded(code);
    if (power.isOn()) {
        motion.switchModeIfNeeded(code);
    }
    rc.resume(code);
}

#pragma clang diagnostic pop
