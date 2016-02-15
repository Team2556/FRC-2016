#ifndef TeleopCommand_H
#define TeleopCommand_H

#include "CommandBase.h"
#include "WPILib.h"
#include "RAR/RARMath.h"

class TeleopCommand: public CommandBase{
public:
	TeleopCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
