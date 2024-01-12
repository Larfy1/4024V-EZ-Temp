#include "shooter.hpp"

#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "pros/llemu.hpp"

Shooter::Shooter(float fireSpeed, float downSpeed, float matchloadSpeed)
    : m_fireSpeed(fireSpeed), m_downSpeed(downSpeed), m_matchloadSpeed(matchloadSpeed),
    m_shooterMotors(std::initializer_list<pros::Motor> {
        pros::Motor(1),
        pros::Motor(-9)
    }),
    m_rotation(4, true) {
}

void Shooter::reset() {
    m_shooterMotors.tare_position();
}

float Shooter::getPosition() {
    return m_rotation.get_angle() / 100.0f;
}

bool Shooter::isUp() {
    float position = getPosition();
    pros::lcd::print(3, "%f", position);

    return position > 355 && position < 5;
}

bool Shooter::isDown() {
    return getPosition() < 308;
}

void Shooter::fire(bool async) {
    if (async) {
        pros::Task task([this](){
            fire(false);
        });
    }

    while (!isDown()) {
        m_shooterMotors.move(m_downSpeed);
        pros::delay(10);
    }

    m_shooterMotors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
    m_shooterMotors.brake();
}

void Shooter::matchload(float time) {
    m_shooterMotors.move(m_matchloadSpeed);
    
    if (time != 0) {
        pros::delay(time);
        stopMatchload();
    }
}

void Shooter::stopMatchload() {
    m_shooterMotors.move(0);
}