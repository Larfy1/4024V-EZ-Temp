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
  chassis.set_pid_constants(&chassis.headingPID, 0, 0, 0, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.25, 0, 0.78, 0);
  chassis.set_pid_constants(&chassis.turnPID, 4, 0, 34.6, 0);
  chassis.set_pid_constants(&chassis.swingPID, 0, 0, 0, 0);
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
  chassis.set_swing_pid(LEFT_SWING, 270, SWING_SPEED-10);
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
  chassis.set_drive_pid(24, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(250);
  intake.stop();
  chassis.set_active_brake(0.1);
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
  chassis.set_drive_pid(-9, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 180, SWING_SPEED);
  chassis.wait_drive();
  // chassis.set_turn_pid(180, TURN_SPEED);
  // chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(300);
  chassis.set_tank(0, 0);
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
  chassis.set_drive_pid(-5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(true);
  chassis.set_drive_pid(31, DRIVE_SPEED+10);
  chassis.wait_drive();
  intake.spin(false);
  pros::delay(150);
  intake.stop();
  wings.setFrontWings(false);
  chassis.set_drive_pid(-21, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(30, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-55, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(120, TURN_SPEED);
  chassis.wait_drive();
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
  pros::delay(250);
  chassis.set_drive_pid(-5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(true);
  chassis.set_drive_pid(31, DRIVE_SPEED+10);
  chassis.wait_drive();
  intake.spin(false);
  pros::delay(150);
  intake.stop();
  wings.setFrontWings(false);
  chassis.set_drive_pid(-15, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-38, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-3, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 180, SWING_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(300);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(7, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 135, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(20, DRIVE_SPEED);
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
  pros::delay(350);
  intake.stop();
  chassis.set_turn_pid(250, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(18, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(270, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(22, DRIVE_SPEED);
  chassis.wait_drive();
  intake.spin(true);
  pros::delay(300);
  chassis.set_drive_pid(-35, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 225, SWING_SPEED);
  chassis.wait_drive();
  wings.setBackWings(true);
  pros::delay(300);
  chassis.set_drive_pid(-15, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setBackWings(false);
  pros::delay(250);
  chassis.set_swing_pid(LEFT_SWING, 180, SWING_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(500);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
  intake.spin(false);
  pros::delay(250);
  intake.stop();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(127, 127);
  pros::delay(500);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(-9, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(24, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(-66, TURN_SPEED);
  chassis.wait_drive();
  // intake.spin(true);
  chassis.set_drive_pid(15, DRIVE_SPEED);
  chassis.wait_drive();
  // pros::delay(300);
  // chassis.set_turn_pid(80, TURN_SPEED);
  // chassis.wait_drive();
}

void skills_macro() {
  chassis.reset_gyro(315);
  chassis.set_turn_pid(315, TURN_SPEED);
  intake.spin(false);
  pros::delay(250);
  chassis.set_drive_pid(15, DRIVE_SPEED);
  chassis.wait_drive();
  intake.stop();
  chassis.set_turn_pid(431, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-4, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_active_brake(0.1);
	shooter.matchload();
  pros::delay(26000);
  shooter.stopMatchload();
  chassis.set_active_brake(0);
}


void skills() {
  skills_macro();
  chassis.set_turn_pid(495, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(24, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 450, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(78, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(405, TURN_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(true);
  chassis.set_drive_pid(19, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(false);
  chassis.set_turn_pid(225, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 180, SWING_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(300);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(10, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(300);
  chassis.set_tank(0, 0);
  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(5, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(270, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(24, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(true);
  chassis.set_swing_pid(LEFT_SWING, 430, SWING_SPEED - 20);
  chassis.wait_drive();
  chassis.set_drive_pid(15, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(450, TURN_SPEED);
  chassis.wait_drive();
  intake.spin(false);
  chassis.mode = ez::DISABLE;
  chassis.set_tank(127, 127);
  pros::delay(500);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(-24, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(127, 127);
  pros::delay(500);
  chassis.set_tank(0, 0);
  intake.stop();
  wings.setFrontWings(false);
  chassis.set_turn_pid(450, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-24, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 540, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-17, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(460, TURN_SPEED);
  chassis.wait_drive();
  intake.spin(false);
  wings.setFrontWings(true);
  chassis.mode = ez::DISABLE;
  chassis.set_tank(127, 127);
  pros::delay(600);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(-24, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(127, 127);
  pros::delay(600);
  chassis.set_tank(0, 0);
  intake.stop();
  wings.setFrontWings(false);
  chassis.set_drive_pid(-27, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(405, TURN_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(true);
  chassis.set_drive_pid(26, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(LEFT_SWING, 495, SWING_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, DRIVE_SPEED);
  chassis.wait_drive();
  wings.setFrontWings(false);
  chassis.set_turn_pid(315, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-19, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_swing_pid(RIGHT_SWING, 360, SWING_SPEED);
  chassis.wait_drive();
  chassis.mode = ez::DISABLE;
  chassis.set_tank(-127, -127);
  pros::delay(300);
  chassis.set_tank(0, 0);
  chassis.set_drive_pid(10, DRIVE_SPEED);
  chassis.wait_drive();
}