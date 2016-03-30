#include "RemoteControl.h"
#include <IRremote.h>
#include <Arduino.h>

RemoteControl::RemoteControl(int irPin) {
    irRecv = new IRrecv(irPin);
};

unsigned long RemoteControl::getIRCode() {
    for (int i = 0; i < 20; i++) {
        if (irRecv->decode(&results)) {
            if (results.value != REPEAT) {
                last = results.value;
            }
            return last;
        }
        delay(10);
    }
    return 0;
}

void RemoteControl::init() {
    irRecv->enableIRIn();
}

void RemoteControl::resume(unsigned long code) {
    if (code != 0) {
        irRecv->resume();
    }
}
