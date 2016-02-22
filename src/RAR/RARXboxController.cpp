/*
 * Name: RARXboxController.cpp
 * Authors: Andrew Parmer
 * Dates: 2015-09-29
 * Description: Creates Xbox Controller Class
 */

#include "RARXboxController.h"

XboxController::XboxController(int Port):
	_Joystick(Port),
	A(&_Joystick, 1),
	B(&_Joystick, 2),
	X(&_Joystick, 3),
	Y(&_Joystick, 4),
	LeftBumper(&_Joystick, 5),
	RightBumper(&_Joystick, 6),
	Back(&_Joystick, 7),
	Start(&_Joystick, 8),
	LeftStick(&_Joystick, 9),
	RightStick(&_Joystick, 10){
}
float XboxController::GetAxis(XboxAxis Axis){
	return _Joystick.GetRawAxis(Axis);
}
