#ifndef AutonomousMain_H
#define AutonomousMain_H

#include "Drive.h"
#include "AlignToGoal.h"
#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutonomousMain: public CommandGroup{
	public:
		AutonomousMain();
		//Drive *DriveC;
};

#endif
