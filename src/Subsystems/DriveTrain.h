#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain:public Subsystem, public PIDOutput{
	private:
		CANTalon *FrontLeft;
		CANTalon *FrontRight;
		CANTalon *BackLeft;
		CANTalon *BackRight;
	public:
		DriveTrain();
		void InitDefaultCommand();
		void Drive(float Power, float Rotation);
		void PIDWrite(float Output);
};

#endif
