#include "intake.hpp"

#include "pros/rtos.hpp"

Intake::Intake(float intakeSpeed)
    : m_intakeSpeed(intakeSpeed), m_intakeMotor(-13) {

}

void Intake::spin(bool direction) {
    m_intakeMotor.move(direction ? m_intakeSpeed : -m_intakeSpeed);
}

void Intake::stop() {
    m_intakeMotor.move(0);
}

void Intake::spinFor(bool direction, float time) {
    spin(direction);
    pros::delay(time);
    stop();
}