#ifndef SkidDrive_H
#define SkidDrive_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../RAR/RARMath.h"

class SkidDrive: public CommandBase{
	public:
		SkidDrive();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};

#endif
