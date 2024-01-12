#pragma once

#include "pros/adi.hpp"

class Hang {
    public:
        Hang();

        void hangUp();

        void hangDown();
    private:
        pros::ADIDigitalOut m_upPiston;
        pros::ADIDigitalOut m_downPiston;
};