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
 * 		A: 0
 * 		B: 1
 * 		X: 2
 * 		Y: 3
 * 		Left Bumper: 4
 * 		Right Bumper: 5
 * 		Back: 6
 * 		Start: 7
 * 		Left Stick (Press): 8
 * 		Right Stick (Press): 9
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
