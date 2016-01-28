/*
 * Name: RARXboxController.cpp
 * Authors: Andrew Parmer
 * Dates: 2015-09-29
 * Description: Creates Xbox Controller Class
 */

#include "RARXboxController.h"

XboxController::XboxController(int Port):
	_Joystick(Port),
	A(&_Joystick, 0),
	B(&_Joystick, 1),
	X(&_Joystick, 2),
	Y(&_Joystick, 3),
	LeftBumper(&_Joystick, 4),
	RightBumper(&_Joystick, 5),
	Back(&_Joystick, 6),
	Start(&_Joystick, 7),
	LeftStick(&_Joystick, 8),
	RightStick(&_Joystick, 9){
}
float XboxController::GetAxis(XboxAxis Axis){
	return _Joystick.GetRawAxis(Axis);
}
