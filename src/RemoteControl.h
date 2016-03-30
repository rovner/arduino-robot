#ifndef ARDUINO_REMOTECONTROL_H
#define ARDUINO_REMOTECONTROL_H

#include <IRremote.h>

static const unsigned long POWER = 0xFFA25D;
static const unsigned long MENU = 0xFFE21D;
static const unsigned long TEST = 0xFF22DD;
static const unsigned long PLUS = 0xFF02FD;
static const unsigned long BACK = 0xFFC23D;
static const unsigned long PREV = 0xFFE01F;
static const unsigned long PLAY = 0xFFA857;
static const unsigned long NEXT = 0xFF906F;
static const unsigned long MINUS = 0xFF9867;
static const unsigned long C = 0xFFB04F;
static const unsigned long _0 = 0xFF6897;
static const unsigned long _1 = 0xFF30CF;
static const unsigned long _2 = 0xFF18E7;
static const unsigned long _3 = 0xFF7A85;
static const unsigned long _4 = 0xFF10EF;
static const unsigned long _5 = 0xFF38C7;
static const unsigned long _6 = 0xFF5AA5;
static const unsigned long _7 = 0xFF42BD;
static const unsigned long _8 = 0xFF4AB5;
static const unsigned long _9 = 0xFF52AD;

class RemoteControl {
public:
    RemoteControl(uint8_t irPin);

    unsigned long getIRCode();

    void resume(unsigned long code);

    void init();

private:
    IRrecv *irRecv;
    decode_results results;
    unsigned long last;
};

#endif //ARDUINO_REMOTECONTROL_H
