#include "main.h"
#include "globals.hpp"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 13, 0, 40, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 1.1, 0, 8.5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 1.1, 0, 8.5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 7, 0.003, 47, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void qual_far() {
  chassis.reset_gyro(270);
  chassis.set_turn_pid(270, TURN_SPEED);
  intake.spin(false);
  pros::delay(250);
  intake.spin(true);
  chassis.set_drive_pid(6, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(250);
  chassis.set_drive_pid(-30, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 225, SWING_SPEED);
  chassis.wait_drive();
  wings.setBackWings(true);
  pros::delay(300);
  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setBackWings(false);
  chassis.set_swing_pid(LEFT_SWING, 180, SWING_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(300);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(20, TURN_SPEED);
  chassis.wait_drive();
  intake.spin(false);
  pros::delay(250);
  intake.stop();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(127, 127);
  pros::delay(300);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(-5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 225, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(24, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 270, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(24, DRIVE_SPEED);
  chassis.wait_drive();
}

void qual_close() {
  chassis.reset_gyro(315);
  chassis.set_turn_pid(315, TURN_SPEED);
  intake.spin(false);
  pros::delay(250);
  chassis.set_drive_pid(10, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setBackWings(true);
  pros::delay(300);
  chassis.set_drive_pid(-3, DRIVE_SPEED);
  chassis.wait_drive();
  intake.stop();
  chassis.set_swing_pid(LEFT_SWING, 270, SWING_SPEED);
  chassis.wait_drive();
  wings.setBackWings(false);
  chassis.set_swing_pid(LEFT_SWING, 315, SWING_SPEED);
  chassis.wait_drive();
  wings.setBackWings(false);
  chassis.set_turn_pid(135, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-13, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 180, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-7.5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-6, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(7, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(135, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(28, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 90, SWING_SPEED);
  chassis.wait_drive();
  intake.spin(false);
  chassis.set_drive_pid(25, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(250);
  intake.stop();
}

void elims_close() {
  chassis.reset_gyro(315);
  chassis.set_turn_pid(315, TURN_SPEED);
  intake.spin(false);
  pros::delay(250);
  chassis.set_drive_pid(7, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(135, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-13, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 180, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(7, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(24, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(15, TURN_SPEED);
  chassis.wait_drive();
  intake.spin(true);
  chassis.set_drive_pid(29, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(250);
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(true);
  chassis.set_drive_pid(26, DRIVE_SPEED+10);
  chassis.wait_drive();
  intake.spin(false);
  pros::delay(150);
  intake.stop();
  wings.setFrontWings(false);
  chassis.set_drive_pid(-21, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(30, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-40, DRIVE_SPEED);
  chassis.wait_drive();
}

void elims_far() {
  chassis.reset_gyro(270);
  chassis.set_turn_pid(270, TURN_SPEED);
  intake.spin(false);
  pros::delay(250);
  intake.spin(true);
  chassis.set_drive_pid(6, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(250);
  chassis.set_drive_pid(-30, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 225, SWING_SPEED);
  chassis.wait_drive();
  wings.setBackWings(true);
  pros::delay(300);
  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setBackWings(false);
  chassis.set_swing_pid(LEFT_SWING, 180, SWING_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(300);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(20, TURN_SPEED);
  chassis.wait_drive();
  intake.spin(false);
  pros::delay(250);
  intake.stop();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(127, 127);
  pros::delay(300);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(-5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(24, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(-40, TURN_SPEED);
  chassis.wait_drive();
  intake.spin(true);
  chassis.set_drive_pid(36, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(250);
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(true);
  intake.spin(false);
  chassis.mode = ez::DISABLE;
  chassis.set_tank(127, 127);
  pros::delay(700);
  chassis.set_tank(0, 0);
  wings.setFrontWings(false);
  chassis.set_drive_pid(-7, DRIVE_SPEED);
  chassis.wait_drive();
}

void elims_far_rush() {
  chassis.reset_gyro(323);
  chassis.set_turn_pid(323, TURN_SPEED);
  intake.spin(false);
  wings.setFrontWings(true);
  pros::delay(250);
  wings.setFrontWings(false);
  intake.spin(true);
  chassis.set_drive_pid(60, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(450, TURN_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(true);
  intake.spin(false);
  chassis.mode = ez::DISABLE;
  chassis.set_tank(120, 127);
  pros::delay(700);
  chassis.set_tank(0, 0);
  wings.setFrontWings(false);
  intake.stop();
  chassis.set_drive_pid(-7, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 265, SWING_SPEED);
  chassis.wait_drive();
  intake.spin(true);
  chassis.set_drive_pid(5, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(150);
  chassis.set_turn_pid(310, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-35, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 420, SWING_SPEED);
  chassis.wait_drive();
  intake.spin(false);
  pros::delay(250);
  intake.stop();
  chassis.set_turn_pid(250, TURN_SPEED);
  chassis.wait_drive();
  wings.setBackWings(true);
  pros::delay(300);
  chassis.set_drive_pid(-7, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(150);
  wings.setBackWings(false);
  pros::delay(150);
  chassis.set_turn_pid(210, TURN_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(500);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(7, DRIVE_SPEED);
  chassis.wait_drive();
}

void skills_macro() {
  chassis.reset_gyro(315);
  chassis.set_turn_pid(315, TURN_SPEED);
  intake.spin(false);
  chassis.set_drive_pid(15, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(71, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-1, DRIVE_SPEED);
  chassis.wait_drive();
  intake.stop();
  wings.setBackWings(true);
  shooter.matchload(30000);
  wings.setBackWings(false);
}


void skills() {
  skills_macro();
  chassis.set_turn_pid(315, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-24, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(270, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-75, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(true);
  chassis.set_drive_pid(19, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(false);
  chassis.set_turn_pid(225, TURN_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(600);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(277, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(45, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(24, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(true);
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(600);
  chassis.set_tank(0, 0);
  wings.setFrontWings(false);
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-30, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(24, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(true);
  chassis.set_turn_pid(120, TURN_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(600);
  chassis.set_tank(0, 0);
  wings.setFrontWings(false);
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-30, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(24, DRIVE_SPEED);
  chassis.set_turn_pid(90, TURN_SPEED);
  wings.setFrontWings(true);
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(600);
  chassis.set_tank(0, 0);
  wings.setFrontWings(false);
}