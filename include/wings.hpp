#pragma once

#include "pros/adi.hpp"

class Wings {
    public:
        Wings();

        void setFrontWings(bool value);

        void setBackWingL(bool value);

        void setBackWingR(bool value);
    private:
        pros::ADIDigitalOut m_frontWings;
        pros::ADIDigitalOut m_backWingL;
        pros::ADIDigitalOut m_backWingR;
};