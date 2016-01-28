#include "SkidDrive.h"

SkidDrive::SkidDrive(){
	Requires(CommandBase::drivetrain.get());
}

void SkidDrive::Initialize(){
}

void SkidDrive::Execute(){
	drivetrain.get()->Drive(DeadSens(oi->Xbox1->GetAxis(LeftY), 0.025, 1), DeadSens(oi->Xbox1->GetAxis(RightX), 0.025, 1));
}

bool SkidDrive::IsFinished(){
	return false;
}

void SkidDrive::End(){
	drivetrain.get()->Drive(0.0, 0.0);
}

void SkidDrive::Interrupted(){
}
