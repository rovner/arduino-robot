#include "PowerController.h"
#include "RemoteControl.h"

bool PowerController::isOn() {
    return on;
}

void PowerController::switchModeIfNeeded(unsigned long code) {
    if (code == POWER) {
        on = !on;
    }
}
