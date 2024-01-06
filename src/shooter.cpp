#include "shooter.hpp"

#include "pros/motors.h"
#include "pros/rtos.hpp"

Shooter::Shooter(float fireSpeed, float downSpeed, float matchloadSpeed)
    : m_fireSpeed(fireSpeed), m_downSpeed(downSpeed), m_matchloadSpeed(matchloadSpeed),
    m_shooterMotors(std::initializer_list<pros::Motor> {
        pros::Motor(1),
        pros::Motor(-9)
    }) {
}

void Shooter::reset() {
    m_shooterMotors.tare_position();
}

float Shooter::getPosition() {
    m_shooterMotors.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
    return m_shooterMotors.get_positions()[0];
}

bool Shooter::isUp() {
    float position = getPosition();

    return position > 0 && position < 10;
}

bool Shooter::isDown() {
    return getPosition() > 250;
}

void Shooter::fire(bool async) {
    if (async) {
        pros::Task task([this](){
            fire();
        });
    }

    while (!isUp()) {
        m_shooterMotors.move(m_fireSpeed);
        pros::delay(10);
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