#include <Arduino.h>
#include "RemoteControl.h"
#include "PowerController.h"
#include "MotorController.h"
#include "MotionController.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
RemoteControl rc(11);
PowerController power;
MotionController motion(new MotorController(12, 7), new MotorController(13, 8));

void setup() {
    Serial.begin(9600);
}

void loop() {
    unsigned long code = rc.getIRCode();
    Serial.println(code, HEX);
    power.switchModeIfNeeded(code);
    if (power.isOn()) {
        motion.switchModeIfNeeded(code);
    }

}
#pragma clang diagnostic pop