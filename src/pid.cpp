#include "robotconfig.hpp"
#include <cmath>

// Drive PID constants
double drive_kP = 0.5;
double drive_kI = 0.0;
double drive_kD = 2.5;

// Turn PID constants
double turn_kP = 2.0;
double turn_kD = 4.5;


// Reset encoders
void resetDriveEncoders() {
    leftDrive.tare_position();
    rightDrive.tare_position();
}


// Average encoder position
double getDrivePosition() {
    return (leftDrive.get_position() + rightDrive.get_position()) / 2.0;
}


// DRIVE PID
void drivePID(double target) {

    resetDriveEncoders();

    double error = 0;
    double prevError = 0;
    double integral = 0;

    while (true) {

        double pos = getDrivePosition();

        error = target - pos;

        integral += error;

        double derivative = error - prevError;

        double power =
            error * drive_kP +
            integral * drive_kI +
            derivative * drive_kD;

        leftDrive.move(power);
        rightDrive.move(power);

        prevError = error;

        if (fabs(error) < 5) break;

        pros::delay(10);
    }

    leftDrive.move(0);
    rightDrive.move(0);
}


// TURN PID
void turnPID(double target) {

    double error;
    double prevError = 0;

    while (true) {

        double heading = imu.get_rotation();

        error = target - heading;

        double derivative = error - prevError;

        double power =
            error * turn_kP +
            derivative * turn_kD;

        leftDrive.move(power);
        rightDrive.move(-power);

        prevError = error;

        if (fabs(error) < 1) break;

        pros::delay(10);
    }

    leftDrive.move(0);
    rightDrive.move(0);
}
