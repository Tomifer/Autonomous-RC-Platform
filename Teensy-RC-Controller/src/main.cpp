#include "../lib/PWM-Reader/PWM.hpp"
#include <Arduino.h>

#define NUM_CHANNELS 6
PWM channel1(33);
PWM channel2(34);
PWM channel3(35);
PWM channel4(36);
PWM channel5(37);
PWM channel6(38);
int readings[6];

void setup()
{
    Serial.begin(115200);
    channel1.begin(true);
    channel2.begin(true);
    channel3.begin(true);
    channel4.begin(true);
    channel5.begin(true);
    channel6.begin(true);
}

void loop()
{
    readings[0] = channel1.getValue();
    readings[1] = channel2.getValue();
    readings[2] = channel3.getValue();
    readings[3] = channel4.getValue();
    readings[4] = channel5.getValue();
    readings[5] = channel6.getValue();
    Serial.print("Channel Data:\t");
    for (int i = 0; i < NUM_CHANNELS; i++) {
        Serial.print(i + 1);
        Serial.print(" [ ");
        Serial.print(map(pulseIn(readings[i], HIGH), 993, 1991, 0, 100));
        Serial.print(" ]   ");
    }
    Serial.println();
    delay(50);
}