#include <Arduino.h>
#include <IRremote.h>
#include "IRCodes.h"

#define LED_PIN 12

IRrecv iRrecv(11);

decode_results results;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
    Serial.println("start");
    iRrecv.enableIRIn();
}

void loop() {
    if (iRrecv.decode(&results)) {
        if (results.value == POWER) {
            digitalWrite(LED_PIN, HIGH);
            delay(50);
            digitalWrite(LED_PIN, LOW);
            delay(50);
            digitalWrite(LED_PIN, HIGH);
            delay(50);
            digitalWrite(LED_PIN, LOW);
            delay(50);
            digitalWrite(LED_PIN, HIGH);
            delay(50);
            digitalWrite(LED_PIN, LOW);
            delay(50);
        } else {
            digitalWrite(LED_PIN, HIGH);
            delay(100);
            digitalWrite(LED_PIN, LOW);
        }
        Serial.println(results.value, HEX);
        iRrecv.resume();
    }
}