#include <Arduino.h>
#include "MOTOR_DRIVER.h"

MOTOR_DRIVER::MOTOR_DRIVER(int in1, int in2, int in3, int in4, int ena, int enb)
  : in1(in1), in2(in2), in3(in3), in4(in4), ena(ena), enb(enb) {}

void MOTOR_DRIVER::begin() {
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(ena, OUTPUT);
    pinMode(enb, OUTPUT);
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

    leftPower = constrain(leftPower, -255, 255);
    rightPower = constrain(rightPower, -255, 255);

    left_pwm_out = leftPower;
    right_pwm_out = rightPower;
}
void MOTOR_DRIVER::move_motors(int pwm, bool m) {
    if(m) {
        if (pwm > 0) {
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            analogWrite(ena, pwm);
        } 
        else if (pwm < 0) {
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            analogWrite(ena, -pwm);
        } 
        else {
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            analogWrite(ena, 0);
        }
    }
    else {
        if (pwm > 0) {
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
            analogWrite(enb, pwm);
        } 
        else if (pwm < 0) {
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
            analogWrite(enb, -pwm);
        } 
        else {
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);
            analogWrite(enb, 0);
        }
    }
}
