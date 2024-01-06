#pragma once

#include "pros/adi.hpp"

class Wings {
    public:
        Wings();

        void setFrontWings(bool value);

        void setBackWings(bool value);
    private:
        pros::ADIDigitalOut m_frontWings;
        pros::ADIDigitalOut m_backWings;
};