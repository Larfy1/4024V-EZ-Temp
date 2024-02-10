#pragma once

#include "pros/adi.hpp"

class Hang {
    public:
        Hang();

        void parkDown();

        void parkUp();
        
        void hangUp();

        void hangDown();
    private:
        pros::ADIDigitalOut m_parkPiston;
        pros::ADIDigitalOut m_upPiston;
        pros::ADIDigitalOut m_downPiston;
};