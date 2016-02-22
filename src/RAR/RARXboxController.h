/*
 * Name: RARXboxController.h
 * Authors: Andrew Parmer
 * Dates: 2015-09-29
 * Description: Creates Xbox Controller Class
 */

#include "WPILib.h"

#ifndef RARXboxController
#define RARXboxController

/*
 * Axes:
 * 		Left Stick: (-1 to 1)
 * 			X Axis: 0
 * 			Y Axis: 1
 * 		Right Stick: (-1 to 1)
 * 			X Axis: 4
 * 			Y Axis: 5
 * 		Left Trigger: 2 (0 to 1)
 * 		Right Trigger: 3 (0 to 1)
 * Buttons:
 * 		A: 1
 * 		B: 2
 * 		X: 3
 * 		Y: 4
 * 		Left Bumper: 5
 * 		Right Bumper: 6
 * 		Back: 7
 * 		Start: 8
 * 		Left Stick (Press): 9
 * 		Right Stick (Press): 10
 */

enum XboxAxis:int{ LeftX, LeftY, LeftT, RightT, RightX, RightY };

class XboxController{
	Joystick _Joystick;
	public:
		JoystickButton A,
			B,
			X,
			Y,
			LeftBumper,
			RightBumper,
			Back,
			Start,
			LeftStick,
			RightStick;
		XboxController(int Port);
		float GetAxis(XboxAxis Axis);
};

#endif
