#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <PS4Controller.h>
// Controller class for managing sensor data and communication
class CONTROLLER {
    public:
        CONTROLLER();
        void begin();
        void set_deadzone();
        void update();

        int deadzone = 0;
        
        //dpad
        bool dup, dright, ddown, dleft;

        //buttons
        bool square, cross, circle, triangle;

        //shoulder buttons
        bool l1, r1;

        //other buttons
        bool share, options, touchpad, psbutton;

        //joystick axes
        int lx, ly, rx, ry;

        //triggers
        int l2, r2;
};
#endif // CONTROLLER_H