#include "main.h"
#include "autons.hpp"
#include "globals.hpp"

pros::IMU inertial(18);

// Chassis constructor
Drive chassis (
  // Left Chassis Ports
  {-15, -16, -17}
  // Right Chassis Ports
  ,{11, 20, 14}
  // IMU Port
  ,18
  // Wheel Diameter
  ,3.25
  // Cartridge RPM
  ,600
  // External Gear Ratio (MUST BE DECIMAL)
  ,1.333
);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {  
  pros::delay(500); // Stop the user from doing anything while legacy ports configure.

  // Configure your chassis controls
  // chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
  // chassis.set_curve_default(0, 0); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
  default_constants(); // Set the drive to your own constants from autons.cpp!

  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.set_left_curve_buttons (pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT); // If using tank, only the left side is used. 
  // chassis.set_right_curve_buttons(pros::E_CONTROLLER_DIGITAL_Y,    pros::E_CONTROLLER_DIGITAL_A);

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.add_autons({
    // Auton("Eliminations Close Rush", elims_close_rush),
    // Auton("Test PID Movements", test)
    // Auton("Eliminations Far Rush Between", elims_far_rush_between),
    // Auton("Qualification Close", qual_close),
    Auton("Skills", skills),
    // Auton("Qualification Far", qual_far),
    // Auton("Eliminations Close Disrupt", elims_close_disrupt),
    // Auton("Eliminations Far", elims_far),
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();
  
  chassis.reset_pid_targets(); // Resets PID targets to 0
  chassis.reset_gyro(); // Reset gyro position to 0
  chassis.reset_drive_sensor(); // Reset drive sensors to 0

  pros::Task task([](){
    pros::Imu imu(18);

    while (true) {
      pros::lcd::print(3, "%f", imu.get_rotation());
      pros::delay(10);
    }
  });
}



/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
}



/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .
}



/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD);
  
  ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.
  // skills_macro();
}



/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {  
	bool backwards = false;
  bool hang_up = false;
  bool park_down = false;

  chassis.set_drive_brake(MOTOR_BRAKE_HOLD);
  // skills_macro();
  chassis.mode = ez::DISABLE;

  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  chassis.set_active_brake(0);

  while (true) {
    if (backwards) {
      chassis.set_tank(-master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y), -master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
    } else {
      chassis.set_tank(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
    }

    // chassis.arcade_standard(ez::SPLIT);

    // if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    //   shooter.matchload();
    // } else {
    //   shooter.stopMatchload();
    // }

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
      if (!park_down) {
        hang.parkDown();
        wings.setBackWingR(true);
      } else {
        hang.parkUp();
        wings.setBackWingR(false);
      }
      park_down = !park_down;
    }

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
      if (shooter.isMatchloading()) {
        shooter.stopMatchload();
      }
      else {
        shooter.matchload();
      }
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      wings.setFrontWings(true);
    } else {
      wings.setFrontWings(false);
    }

    if (backwards) {
      if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        wings.setBackWingR(true);
      } else if(!park_down) {
        wings.setBackWingR(false);
      }

      if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
        wings.setBackWingL(true);
      } else {
        wings.setBackWingL(false);
      }
    } else {
      if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        wings.setBackWingL(true);
      } else {
        wings.setBackWingL(false);
      }

      if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
        wings.setBackWingR(true);
      } else if(!park_down) {
        wings.setBackWingR(false);
      }
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      intake.spin(true);
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      intake.spin(false);
    } else {
      intake.stop();
    }

		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
			backwards = !backwards;
		}

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
      if(hang_up) hang.hangDown();
      else hang.hangUp();
      hang_up = !hang_up;
    }

    pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
