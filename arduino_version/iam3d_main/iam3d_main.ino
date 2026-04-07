#include <Arduino.h>
#include "CONTROLLER.h"
#include "MOTOR_DRIVER.h"
#include "map"
#include <ESP32Servo.h>

// PIN CONNECTIONS
// const int builtInLed = 2;
// const int deadzone = 10;

// //motorpins
int ENApin = 14; //motor 1 speed
int IN1pin = 33; //motor 1 dir1
int IN2pin = 26; //motor 1 dir2
int IN3pin = 32; //motor 2 dir1
int IN4pin = 25; //motor 2 dir2
int ENBpin = 12; //motor 2 speed
//MOTOR_DRIVER::MOTOR_DRIVER(int in1, int in2, int in3, int in4, int ena, int enb)
int value = 1; // integer to track input of Square for Dumping mechanism
int check = 1;

//create objects
CONTROLLER ps4;
MOTOR_DRIVER motorDriver(IN1pin, IN2pin, IN3pin, IN4pin, ENApin, ENBpin);

//prototypes
// void driveLeftMotor(int pwm);
// void driveRightMotor(int pwm);

void setup() {
  //initialize serial communication
  Serial.begin(115200);

  //begin controller
  ps4.begin();
  motorDriver.begin();

  Serial.println("Ready.");
  delay(5000);
}

void loop() {
  ps4.update();
  Serial.printf("LX: %d, LY: %d\n", ps4.lx, ps4.ly);
  motorDriver.drive(ps4.lx, ps4.ly);

if ps4.square = 1 && check = 0  {
  value = value + 1;
  check = 1
  if (value % 2 == 0) {
    set.servo = 150;
  }
  else {
    set.servo = 0;
  }
}

if ps4.square = 0 {
  check = 0;
}
  // int leftPower = ps4.ly + ps4.lx;
  // int rightPower = ps4.ly - ps4.lx;

  // leftPower = constrain(leftPower, -128, 127);
  // rightPower = constrain(rightPower, -128, 127);

  // int leftPWM = map(leftPower, -128, 127, 0, 255);
  // int rightPWM = map(rightPower, -128, 127, 0, 255);

  // driveLeftMotor(leftPWM);
  // driveRightMotor(rightPWM);

  //delay();
}

// void driveLeftMotor(int pwm) {
//   if (pwm > 0) {
//     digitalWrite(IN1pin, HIGH);
//     digitalWrite(IN2pin, LOW);
//     analogWrite(ENApin, pwm);
//   } 
//   else if (pwm < -0) {
//     digitalWrite(IN1pin, LOW);
//     digitalWrite(IN2pin, HIGH);
//     analogWrite(ENApin, -pwm);
//   } 
//   else {
//     analogWrite(ENApin, 0); //stop
//   }
// }

// void driveRightMotor(int pwm) {
//   if (pwm > 0) {
//     digitalWrite(IN3pin, HIGH);
//     digitalWrite(IN4pin, LOW);
//     analogWrite(ENBpin, pwm);
//   } 
//   else if (pwm < -0) {
//     digitalWrite(IN3pin, LOW);
//     digitalWrite(IN4pin, HIGH);
//     analogWrite(ENBpin, -pwm);
//   } 
//   else {
//     analogWrite(ENBpin, 0); //stop
//   }
// }