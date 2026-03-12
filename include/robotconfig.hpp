#pragma once
#include "pros/apix.h"

// Motor groups
extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;

// Individual motors   
extern pros::Motor topRoller;
extern pros::Motor intake;

// IMU
extern pros::Imu imu;

// PID functions
void drivePID(double target);
void turnPID(double target);