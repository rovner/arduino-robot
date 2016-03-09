#include "RemoteControl.h"
#include <IRremote.h>
#include <Arduino.h>

RemoteControl::RemoteControl(int irPin) {
    irRecv = new IRrecv(irPin);
};

unsigned long RemoteControl::getIRCode() {
    if (!initialized) {
        irRecv->enableIRIn();
        initialized = true;
    }
    for (int i = 0; i < 10; i++) {
        if (irRecv->decode(&results)) {
            irRecv->resume();
            return results.value;
        }
        delay(20);
    }
    return 0;
}
