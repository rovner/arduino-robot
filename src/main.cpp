#include <sys/cdefs.h>
#include <Arduino.h>
#include <IRremote.h>

#define LED_PIN 12

IRrecv iRrecv(11, 13);

decode_results results;

void __unused setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
    Serial.println("start");
    iRrecv.enableIRIn();
}

void __unused loop() {
    digitalWrite(LED_PIN, HIGH);
    if (iRrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        digitalWrite(LED_PIN, LOW);
        delay(200);
        iRrecv.resume();
    }
}