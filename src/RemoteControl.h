#ifndef ARDUINO_REMOTECONTROL_H
#define ARDUINO_REMOTECONTROL_H

#include <IRremote.h>

#define POWER 0xFFA25D
#define MENU 0xFFE21D
#define TEST 0xFF22DD
#define PLUS 0xFF02FD
#define BACK 0xFFC23D
#define PREV 0xFFE01F
#define PLAY 0xFFA857
#define NEXT 0xFF906F
#define MINUS 0xFF9867
#define C 0xFFB04F
#define _0 0xFF6897
#define _1 0xFF30CF
#define _2 0xFF18E7
#define _3 0xFF7A85
#define _4 0xFF10EF
#define _5 0xFF38C7
#define _6 0xFF5AA5
#define _7 0xFF42BD
#define _8 0xFF4AB5
#define _9 0xFF52AD

class RemoteControl {
public:
    RemoteControl(int irPin);

    unsigned long getIRCode();
    void resume(unsigned long code);
    void init();

private:
    IRrecv *irRecv;
    decode_results results;
    unsigned long last;
};

#endif //ARDUINO_REMOTECONTROL_H
