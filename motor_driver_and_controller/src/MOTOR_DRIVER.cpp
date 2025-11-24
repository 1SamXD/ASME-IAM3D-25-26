#include <Arduino.h>
#include "MOTOR_DRIVER.h"

MOTOR_DRIVER::MOTOR_DRIVER(int m1_1, int m1_2, int m2_1, int m2_2, int en1, int en2)
  : m1_1(m1_1), m1_2(m1_2), m2_1(m2_1), m2_2(m2_2), en1(en1), en2(en2) {}

void MOTOR_DRIVER::begin() {
    pinMode(m1_1, OUTPUT);
    pinMode(m1_2, OUTPUT);
    pinMode(m2_1, OUTPUT);
    pinMode(m2_2, OUTPUT);
    pinMode(en1, OUTPUT);
    pinMode(en2, OUTPUT);
}

void MOTOR_DRIVER::drive(int ly, int lx) {
    int l, r = get_pwm(ly, lx);
    Serial.printf("Left PWM: %d, Right PWM: %d\n", l, r);
    move_motors(l,1);
    move_motors(r,0);
}

int MOTOR_DRIVER::get_pwm(int ly, int lx) {
    int leftPower = ly + lx;
    int rightPower = ly - lx;

    leftPower = constrain(leftPower, -128, 127);
    rightPower = constrain(rightPower, -128, 127);

    int leftPWM = map(leftPower, -128, 127, 0, 255);
    int rightPWM = map(rightPower, -128, 127, 0, 255);
    return leftPWM, rightPWM;
}

void MOTOR_DRIVER::move_motors(int pwm, bool m) {
    if(m) {
        if (pwm > 0) {
            digitalWrite(m1_1, HIGH);
            digitalWrite(m1_2, LOW);
            analogWrite(en1, pwm);
        } 
        else if (pwm < 0) {
            digitalWrite(m1_1, LOW);
            digitalWrite(m1_2, HIGH);
            analogWrite(en1, -pwm);
        } 
        else {
            digitalWrite(m1_1, LOW);
            digitalWrite(m1_2, LOW);
            analogWrite(en1, 0);
        }
    }
    else {
        if (pwm > 0) {
            digitalWrite(m2_1, HIGH);
            digitalWrite(m2_2, LOW);
            analogWrite(en2, pwm);
        } 
        else if (pwm < 0) {
            digitalWrite(m2_1, LOW);
            digitalWrite(m2_2, HIGH);
            analogWrite(en2, -pwm);
        } 
        else {
            digitalWrite(m2_1, LOW);
            digitalWrite(m2_2, LOW);
            analogWrite(en2, 0);
        }
    }
}
