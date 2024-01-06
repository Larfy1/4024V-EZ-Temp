#pragma once

#include "pros/motors.hpp"

class Intake {
    public:
        Intake(float intakeSpeed = 127);

        void spin(bool direction);

        void stop();

        void spinFor(bool direction, float time);
    private:
        float m_intakeSpeed;

        pros::Motor m_intakeMotor;
};