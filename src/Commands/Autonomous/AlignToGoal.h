#ifndef AlignToGoal_H
#define AlignToGoal_H

#include "CommandBase.h"
#include "WPILib.h"
#include "IMU.h"

extern IMU *NavX;

class AlignToGoal:public CommandBase{
private:
	std::shared_ptr<NetworkTable> _Table;
public:
	PIDController *PID;
	AlignToGoal();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
