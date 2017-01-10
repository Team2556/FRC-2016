#include "Climber.h"
#include "../RobotMap.h"

Climber::Climber():Subsystem("Climber"){
	Winch1 = new CANTalon(WINCH_1);
	Winch2 = new CANTalon(WINCH_2);

	LiftBottom = new CANTalon(BOTTOM_LIFT);
	LiftTop = new CANTalon(TOP_LIFT);

	Winch2->SetControlMode(CANSpeedController::kFollower);
	Winch2->Set(WINCH_1);

	Winch1->SetVoltageRampRate(6.0);
}

void Climber::InitDefaultCommand(){

}

void Climber::setMotors(float motorPower){
	Winch1->Set(motorPower);
}

void Climber::bottomLift(float power){
	LiftBottom->Set(power);
}

void Climber::topLift(float power){
	LiftTop->Set(power);
}
