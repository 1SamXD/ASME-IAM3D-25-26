#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

class MOTOR_DRIVER {
    public:
        MOTOR_DRIVER(int in1, int in2, int in3, int in4, int ena, int enb);
        void begin();
        void drive(int ly, int lx);
        void get_pwm(int ly, int lx, int &left_pwm_out, int &right_pwm_out);
        void move_motors(int pwm, bool m);
        void stop();

    private:
        int in1;
        int in2;
        int in3;
        int in4;
        int ena;
        int enb;
};

#endif // MOTOR_DRIVER_H