#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

class MOTOR_DRIVER {
    public:
        MOTOR_DRIVER(int m1_1, int m1_2, int m2_1, int m2_2, int en1, int en2);
        void begin();
        void drive(int ly, int lx);
        void get_pwm(int ly, int lx, int &left_pwm_out, int &right_pwm_out);
        void move_motors(int pwm, bool m);
        void stop();

    private:
        int m1_1;
        int m1_2;
        int m2_1;
        int m2_2;
        int en1;
        int en2;
};

#endif // MOTOR_DRIVER_H