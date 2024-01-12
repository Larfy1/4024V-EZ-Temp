#include "hang.hpp"

#include "pros/rtos.hpp"

Hang::Hang()
    : m_upPiston('C'), m_downPiston('D') {

}

void Hang::hangUp() {
    pros::Task task([this]() {
        m_downPiston.set_value(false);
        pros::delay(500);
        m_upPiston.set_value(true);
    });
}

void Hang::hangDown() {
    pros::Task task([this]() {
        m_upPiston.set_value(false);
        pros::delay(500);
        m_downPiston.set_value(true);
    });
}