#include <Arduino.h>
#include <Servo.h>

#define THROTTLE_PER 10
#define THROTTLE_CON 11
#define THROTTLE_REC 13

#define SERVO_PER 100
#define SERVO_CON 10
#define SERVO_REC 12

Servo servo;
Servo throttle;

int ranges[] = { 971, 1985, 1062, 1891 };

int min = 2000;
int max = 1000;

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;

    pinMode(THROTTLE_REC, INPUT);
    pinMode(SERVO_REC, INPUT);
    servo.attach(SERVO_CON);
    throttle.attach(THROTTLE_CON);
}

void perfromServoCalculations()
{
    float servoData = pulseIn(SERVO_REC, HIGH);
    Serial.print("\nServo: ");
    Serial.println(servoData);
    servoData = float(map(servoData, ranges[0], ranges[1], 0, 18000)) / 100.0;
    servo.write(servoData);
}

void perfromThrottleCalculations()
{
    float throttleData = pulseIn(THROTTLE_REC, HIGH);
    Serial.print("Throttle: ");
    Serial.println(throttleData);
    throttleData = float(map(throttleData, ranges[2], ranges[3], 0, 18000)) / 100.0;
    throttle.write(throttleData);
}

float getPulseIn(int pin)
{
    int count = 0;
    for (int i = 0; i < 5; i++) {
        count += pulseIn(pin, HIGH);
    }
    return count / 5.0;
}

void loop()
{
    perfromServoCalculations();
    perfromThrottleCalculations();
}