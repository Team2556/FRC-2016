#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

// CAN
const int FRONT_LEFT_MOTOR = 1;
const int FRONT_RIGHT_MOTOR = 3;
const int BACK_LEFT_MOTOR = 2;
const int BACK_RIGHT_MOTOR = 4;

const int TOP_SHOOTER_MOTOR = 5;
const int BOTTOM_SHOOTER_MOTOR = 7;

const int SHOOTER_GIMBAL = 6;

const int WINCH_1 = 8;
const int WINCH_2 = 9;

const int BOTTOM_LIFT = 11;
const int TOP_LIFT = 10;

// PWM
const int TOP_BANANA_SERVO = 0;
const int BOTTOM_BANANA_TALON = 1;
const int VISION_LEDS = 2;

// Analog
const int POTENTIOMETER = 0;

// Digital IO
const int BOTTOM_BANNANA_UPPER_LIMIT = 0;
const int BOTTOM_BANNANA_LOWER_LIMIT = 1;

#endif
