#ifndef Climber_H
#define Climber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Climber: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon *Winch1;
	CANTalon *Winch2;
public:
	Climber();
	void InitDefaultCommand();
	void setMotors(float motorPower);
};

#endif
