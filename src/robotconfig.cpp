#include "robotconfig.hpp"

// Motor groups
pros::MotorGroup leftDrive({-18, -20, -19});
pros::MotorGroup rightDrive({3, 2, 4});

pros::Motor topRoller(11);
pros::Motor intake(7);

 pros::Imu imu(21);

 pros::adi::Pneumatics Match_loader('A', false);
 pros::adi::Pneumatics descore('B', false);