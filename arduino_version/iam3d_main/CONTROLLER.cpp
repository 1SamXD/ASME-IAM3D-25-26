#include <Arduino.h>
#include "CONTROLLER.h"

CONTROLLER::CONTROLLER() {
    Serial.println("Controller object created.");
}  

void CONTROLLER::begin() {
    PS4.begin("B4:2D:9B:12:4B:00");//("DC:AF:68:99:84:5F"); B42D9B124B00

    if (!PS4.isConnected()) {
        Serial.println("Waiting for PS4 controller connection...");
        while (!PS4.isConnected()) {
            delay(100);
        }
    }
    set_deadzone();
    Serial.println("PS4 Controller connected.");
}

void CONTROLLER::set_deadzone() {
    // Deadzone can be set here if needed
    for(int i = 0; i < 10; i++) {
        deadzone = max(deadzone, max(max(abs(PS4.RStickX()), abs(PS4.RStickY())), max(abs(PS4.LStickX()), abs(PS4.LStickY()))));
        delay(10);
    }
    Serial.printf("Deadzone set to: %d\n", deadzone);
}

void CONTROLLER::update() {
    if (!PS4.isConnected()) {
        return;
    }

    //dpad
    dup = PS4.Up();
    dright = PS4.Right();
    ddown = PS4.Down();
    dleft = PS4.Left();

    //buttons
    square = PS4.Square();
    cross = PS4.Cross();
    circle = PS4.Circle();
    triangle = PS4.Triangle();

    //shoulder buttons
    l1 = PS4.L1();
    r1 = PS4.R1();
    
    //other buttons
    share = PS4.Share();
    options = PS4.Options();
    touchpad = PS4.Touchpad();
    psbutton = PS4.PSButton();

    //joystick axes
    //left x
    int rawLX = PS4.LStickX();
    if (abs(rawLX) > deadzone) {
        lx = rawLX;
    } else {
        lx = 0;
    }

    //left y
    int rawLY = PS4.LStickY();
    if (abs(rawLY) > deadzone) {
        ly = rawLY;
    } else {
        ly = 0;
    }

    //right x
    int rawRX = PS4.RStickX();
    if (abs(rawRX) > deadzone) {
        rx = rawRX;
    } else {
        rx = 0;
    }

    //right y
    int rawRY = PS4.RStickY();
    if (abs(rawRY) > deadzone) {
        ry = rawRY;
    } else {
        ry = 0;
    }

    //triggers
    l2 = PS4.L2Value();
    r2 = PS4.R2Value();

    Serial.println("Controller state updated.");
}