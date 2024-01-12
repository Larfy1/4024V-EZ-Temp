#pragma once

#include "pros/motors.hpp"
#include "pros/rotation.hpp"

class Shooter {
    public:
        Shooter(float fireSpeed, float downSpeed, float matchloadSpeed);

        void reset();

        float getPosition();

        bool isUp();

        bool isDown();

        void fire(bool async = false);

        void matchload(float time = 0);

        void stopMatchload();
    private:
        float m_fireSpeed;
        float m_downSpeed;
        float m_matchloadSpeed;

        pros::MotorGroup m_shooterMotors;
        pros::Rotation m_rotation;
};