#pragma once

#include "EZ-Template/drive/drive.hpp"
#include "pros/motors.hpp"
#include "pros/adi.hpp"

pros::ADIDigitalOut wingsF('a');
pros::ADIDigitalOut wingsB('b');
pros::ADIDigitalOut hangUp('c');
pros::ADIDigitalOut hang('d');

pros::Motor intake(13);

pros::MotorGroup shooter(std::initializer_list<pros::Motor> {
        pros::Motor(1),
        pros::Motor(-9)
    });
pros::Rotation shooterRot(4);

extern Drive chassis;

void drive_example();
void turn_example();
void drive_and_turn();
void wait_until_change_speed();
void swing_example();
void combining_movements();
void interfered_example();
void qual_far();
void qual_far_safe();
void qual_close();
void elims_far();
void elims_close();

void default_constants();
void one_mogo_constants();
void two_mogo_constants();