#ifndef PID_H
#define PID_H

// Drive PID constants
extern double drive_kP;
extern double drive_kI;
extern double drive_kD;

// Turn PID constants
extern double turn_kP;
extern double turn_kD;

// Function declarations
void resetDriveEncoders();
double getDrivePosition();
void drivePID(double target);
void turnPID(double target);

#endif // PID_H
