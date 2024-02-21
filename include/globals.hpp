#pragma once 

constexpr int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
constexpr int TURN_SPEED  = 90;
constexpr int SWING_SPEED = 90;

#include "intake.hpp"
#include "shooter.hpp"
#include "wings.hpp"
#include "hang.hpp"

extern Intake intake;
extern Shooter shooter;
extern Wings wings;
extern Hang hang;