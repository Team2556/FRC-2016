#include "Climber.h"
#include "../RobotMap.h"

Climber::Climber():Subsystem("Climber"){
	Winch1 = new CANTalon(WINCH_1);
	Winch2 = new CANTalon(WINCH_2);
}

void Climber::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Climber::setMotors(float motorPower){
	Winch1->Set(motorPower);
	Winch2->Set(motorPower);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
