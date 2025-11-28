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
    int left_pwm, right_pwm;
    get_pwm(ly, lx, left_pwm, right_pwm); 

    Serial.printf("Left PWM: %d, Right PWM: %d\n", left_pwm, right_pwm);
    
    move_motors(left_pwm, 1);  
    move_motors(right_pwm, 0);
}

void MOTOR_DRIVER::get_pwm(int ly, int lx, int &left_pwm_out, int &right_pwm_out) {
    int leftPower = ly + lx;
    int rightPower = ly - lx;

    leftPower = constrain(leftPower, -127, 127);
    rightPower = constrain(rightPower, -127, 127);

    left_pwm_out = leftPower;
    right_pwm_out = rightPower;
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
