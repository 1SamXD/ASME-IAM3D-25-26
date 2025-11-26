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
    lx = PS4.LStickX() + deadzone;
    ly = PS4.LStickY() + deadzone;
    rx = PS4.RStickX() + deadzone;
    ry = PS4.RStickY() + deadzone;

    //triggers
    l2 = PS4.L2Value();
    r2 = PS4.R2Value();

    Serial.println("Controller state updated.");
}