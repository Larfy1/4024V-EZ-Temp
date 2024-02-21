#include "EZ-Template/util.hpp"
#include "main.h"
#include "globals.hpp"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 0, 0, 0, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.75, 0, 6.4, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.75, 0, 6.4, 0);
  chassis.set_pid_constants(&chassis.turnPID, 2.28, 0, 16, 0);
  chassis.set_pid_constants(&chassis.swingPID, 4.50, 0, 51.20, 0);
}

void test() {
  chassis.reset_gyro(180);
  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.set_swing_pid(RIGHT_SWING, 70, SWING_SPEED);
  chassis.wait_drive();
  // chassis.wait_drive();
  // chassis.set_turn_pid(180, TURN_SPEED);
  // chassis.wait_drive();
  // chassis.set_turn_pid(270, TURN_SPEED);
  // chassis.wait_drive();
  // chassis.set_turn_pid(360, TURN_SPEED);
  // chassis.wait_drive();
  // chassis.set_drive_pid(24, DRIVE_SPEED);
  // chassis.wait_drive();
  // chassis.set_turn_pid(180, TURN_SPEED);
  // chassis.wait_drive();
  // chassis.set_drive_pid(24, DRIVE_SPEED);
  // chassis.wait_drive();
  // chassis.set_turn_pid(270, TURN_SPEED);
  // chassis.wait_drive();
  // chassis.set_drive_pid(24, DRIVE_SPEED);
  // chassis.wait_drive();
  // chassis.set_turn_pid(360, TURN_SPEED);
  // chassis.wait_drive();
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
  wings.setBackWingL(true);
  pros::delay(300);
  chassis.set_drive_pid(-14, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setBackWingL(false);
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
  chassis.set_drive_pid(22, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 270, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(26, DRIVE_SPEED);
  chassis.wait_drive();
}

void qual_close() {
  chassis.reset_gyro(315);
  chassis.set_turn_pid(315, TURN_SPEED);
  intake.spin(false);
  pros::delay(250);
  chassis.set_drive_pid(10, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setBackWingL(true);
  pros::delay(250);
  chassis.set_drive_pid(-3, DRIVE_SPEED);
  chassis.wait_drive();
  intake.stop();
  chassis.set_swing_pid(LEFT_SWING, 270, SWING_SPEED);
  chassis.wait_drive();
  wings.setBackWingL(false);
  chassis.set_swing_pid(LEFT_SWING, 315, SWING_SPEED);
  chassis.wait_drive();
  //wings.setBackWingL(false);
  chassis.set_turn_pid(135, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-7, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 180, SWING_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(300);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(7, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(135, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(29, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 90, SWING_SPEED);
  chassis.wait_drive();
  intake.spin(false);
  chassis.set_drive_pid(29, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(250);
  intake.stop();
}

void elims_close_rush() {
  chassis.reset_gyro(20);
  chassis.set_turn_pid(20, TURN_SPEED);
  intake.spin(false);
  wings.setFrontWings(true);
  pros::delay(250);
  wings.setFrontWings(false);
  intake.spin(true);
  chassis.set_drive_pid(49, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(30, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-48, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setBackWingL(true);
  pros::delay(150);
  chassis.set_turn_pid(-225, TURN_SPEED);
  chassis.wait_drive();
  pros::delay(100);
  wings.setBackWingL(false);
  chassis.set_drive_pid(-15, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, -180, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(8, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-9, DRIVE_SPEED+10);
  chassis.wait_drive();
  chassis.set_drive_pid(9, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, -225, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(25, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, -270, SWING_SPEED);
  chassis.wait_drive();
  intake.spin(false);
  pros::delay(250);
  chassis.set_drive_pid(30, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-30, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, -250, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, DRIVE_SPEED);
  chassis.wait_drive();
}

void elims_close_disrupt() {
  chassis.reset_gyro(0);
  chassis.set_turn_pid(0, TURN_SPEED);
  intake.spin(false);
  wings.setFrontWings(true);
  pros::delay(250);
  wings.setFrontWings(false);
  intake.stop();
  chassis.set_drive_pid(45, DRIVE_SPEED);
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
  wings.setBackWingL(true);
  pros::delay(300);
  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setBackWingL(false);
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

void elims_far_rush_safe() {
  chassis.reset_gyro(340);
  chassis.set_turn_pid(340, TURN_SPEED);
  intake.spin(false);
  wings.setFrontWings(true);
  pros::delay(250);
  wings.setFrontWings(false);
  intake.spin(true);
  chassis.set_drive_pid(50, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(150);
  chassis.set_drive_pid(-50, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(405, TURN_SPEED);
  chassis.wait_drive();
  intake.spin(false);
  chassis.set_drive_pid(-10, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(250);
  intake.stop();
  chassis.set_turn_pid(270, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(31, DRIVE_SPEED);
  chassis.wait_drive();
  intake.spin(true);
  pros::delay(350);
  chassis.set_drive_pid(-30, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 225, SWING_SPEED);
  chassis.wait_drive();
  wings.setBackWingL(true);
  pros::delay(300);
  chassis.set_drive_pid(-17, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setBackWingL(false);
  pros::delay(250);
  chassis.set_swing_pid(LEFT_SWING, 180, SWING_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(350);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
  intake.spin(false);
  pros::delay(500);
  intake.stop();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(127, 127);
  pros::delay(450);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(-14, DRIVE_SPEED + 10);
  chassis.wait_drive();
  chassis.set_turn_pid(-75, TURN_SPEED);
  chassis.wait_drive();
  intake.spin(true);
  chassis.set_drive_pid(48, DRIVE_SPEED + 10);
  chassis.wait_drive();
  pros::delay(150);
  chassis.set_turn_pid(65, TURN_SPEED);
  chassis.wait_drive();
  // wings.setFrontWings(true);
  chassis.mode = ez::DISABLE;
  chassis.set_tank(127, 127);
  pros::delay(600);
  chassis.set_tank(0, 0);
  wings.setFrontWings(false);
  chassis.set_drive_pid(-10, DRIVE_SPEED);
  chassis.wait_drive();
  intake.stop();
}

void skills_macro() {
  chassis.reset_gyro(151);
  chassis.set_turn_pid(151, TURN_SPEED);
  intake.spin(false);
  chassis.set_drive_pid(-24, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 180, SWING_SPEED);
  chassis.wait_drive();
  intake.stop();
  chassis.set_drive_pid(10, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(500);
  chassis.set_tank(0, 0);
  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(2, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 75, SWING_SPEED-10);
  chassis.wait_drive();
  chassis.set_drive_pid(-3, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setBackWingR(true);
  pros::delay(500);
  intake.spin(false);
  shooter.matchload();
  pros::delay(22000);
  // pros::delay(2000);
  shooter.stopMatchload();
  intake.stop();
  wings.setBackWingR(false);
}


void skills() {
  skills_macro();
  chassis.set_turn_pid(60, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(34, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(true);
  intake.spin(false);
  chassis.set_drive_pid(68, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
  intake.stop();
  wings.setFrontWings(false);
  chassis.set_drive_pid(-15, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(32, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 90, SWING_SPEED);
  chassis.wait_drive();
  intake.spin(false);
  chassis.set_drive_pid(75, DRIVE_SPEED);
  chassis.wait_until(24);
  wings.setFrontWings(true);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 135, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(28, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(127, 110);
  pros::delay(500);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(-10, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(127, 127);
  pros::delay(500);
  chassis.set_tank(0, 0);
  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(false);
  chassis.set_drive_pid(-15, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(65, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-24, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setBackWingL(true);
  chassis.set_swing_pid(LEFT_SWING, -70, SWING_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -80);
  pros::delay(500);
  chassis.set_tank(0, 0);
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setBackWingL(false);
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-15, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, -90, SWING_SPEED);
  chassis.wait_drive();
  wings.setBackWingL(true);
  wings.setBackWingR(true);
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(500);
  chassis.set_tank(0, 0);
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(25, DRIVE_SPEED);
  chassis.wait_until(5);
  wings.setBackWingL(false);
  wings.setBackWingR(false);
  chassis.wait_drive();
  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-25, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(-120, TURN_SPEED);
  chassis.wait_drive();
  wings.setBackWingR(true);
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-80, -127);
  pros::delay(750);
  chassis.set_tank(0, 0);
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(20, DRIVE_SPEED);
  chassis.wait_until(10);
  wings.setBackWingR(false);
  chassis.wait_drive();
  chassis.set_turn_pid(-22, TURN_SPEED);
  chassis.wait_drive();
  wings.setBackWingR(true);
  chassis.set_drive_pid(-36, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, -135, SWING_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -80);
  pros::delay(500);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(10, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_tank(-127, -127);
  pros::delay(500);
  chassis.set_tank(0, 0);
}