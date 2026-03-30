#include <Arduino.h>
#include "CONTROLLER.h"
#include "MOTOR_DRIVER.h"
#include "map"
#include <ESP32Servo.h>

// PIN CONNECTIONS
// const int builtInLed = 2;
// const int deadzone = 10;

// drivetrain motor pins
int ENApin = 14; //motor 1 speed
int IN1pin = 33; //motor 1 dir1
int IN2pin = 26; //motor 1 dir2
int IN3pin = 32; //motor 2 dir1
int IN4pin = 25; //motor 2 dir2
int ENBpin = 12; //motor 2 speed

//create objects
CONTROLLER ps4;
MOTOR_DRIVER drivetrain(IN1pin, IN2pin, IN3pin, IN4pin, ENApin, ENBpin);

//servo pin
int servoPin = 2;
Servo servo;

//dumper logic variables
int value = 1; // integer to track input of Square for Dumping mechanism
int check = 1;


void setup() {
  //initialize serial communication
  Serial.begin(115200);

  //begin controller
  ps4.begin();
  drivetrain.begin();

  servo.attach(servoPin);

  Serial.println("Ready.");
  delay(5000);
}

void loop() {
  ps4.update();
  Serial.printf("LX: %d, LY: %d\n", ps4.lx, ps4.ly);
  drivetrain.drive(ps4.lx, ps4.ly);

  if (ps4.square == 1 && check == 0) {
    value = value + 1;
    check = 1;
    if (value % 2 == 0) {
      servo.write(150);
    }
    else {
      servo.write(0);
    }
  }

  else if (ps4.square == 0) {
    check = 0;
  }
}