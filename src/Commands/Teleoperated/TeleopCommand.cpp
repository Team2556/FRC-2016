#include "TeleopCommand.h"

TeleopCommand::TeleopCommand(){
	Requires(CommandBase::drivetrain.get());
	Requires(CommandBase::shooter.get());
}

void TeleopCommand::Initialize(){

}

void TeleopCommand::Execute(){
	drivetrain.get()->Drive(-DeadSens(oi->Xbox1->GetAxis(LeftY), 0.025, 0.85), DeadSens(oi->Xbox1->GetAxis(RightX), 0.025, 0.85));

	shooter.get()->SetGimbal(oi->Xbox2->GetAxis(RightY));
	shooter.get()->SetMotors(oi->Xbox2->GetAxis(LeftT), oi->Xbox2->GetAxis(RightT));
	shooter.get()->SetBananas((1 - DeadSens(oi->Xbox1->GetAxis(RightT), 0.025, 1)) * 360, DeadSens(oi->Xbox1->GetAxis(LeftT), 0.025, 1) * 360);
}

bool TeleopCommand::IsFinished(){
	return false;
}

void TeleopCommand::End(){
	drivetrain.get()->Drive(0.0, 0.0);
}

void TeleopCommand::Interrupted(){

}
