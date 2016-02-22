#include "TeleopCommand.h"

TeleopCommand::TeleopCommand(){
	Requires(drivetrain.get());
	Requires(shooter.get());
	Requires(climber.get());
}

void TeleopCommand::Initialize(){

}

void TeleopCommand::Execute(){
	drivetrain.get()->Drive(-DeadSens(oi->Xbox1->GetAxis(LeftY), 0.025, 0.85), DeadSens(oi->Xbox1->GetAxis(RightX), 0.025, 0.85));

	shooter.get()->SetGimbal(DeadSens(oi->Xbox2->GetAxis(LeftY), 0.025, 0.3));
	//shooter.get()->SetMotors(oi->Xbox2->GetAxis(LeftT), oi->Xbox2->GetAxis(RightT));
	if (oi->Xbox2->A.Get())
		shooter.get()->SetMotors(-0.7, 0.6);
	else if (oi->Xbox2->B.Get())
		shooter.get()->SetMotors(-0.5, -0.5);/*
	else if (oi->Xbox2->X.Get())
		shooter.get()->SetMotors(0.25, 0.25);*/
	else if (oi->Xbox2->Y.Get())
		shooter.get()->SetMotors(1.0, 1.0);
	else
		shooter.get()->SetMotors(0.0, 0.0);

	shooter.get()->SetBananas((1 - DeadSens(oi->Xbox2->GetAxis(LeftT), 0.025, 1)), DeadSens(oi->Xbox2->GetAxis(RightT), 0.025, 1));

	SmartDashboard::PutNumber("DB/Slider 0", shooter.get()->getPot());

	if (oi->Xbox2->RightBumper.Get())
		climber.get()->setMotors(1.0);
	else if (oi->Xbox2->LeftBumper.Get())
		climber.get()->setMotors(-1.0);
	else
		climber.get()->setMotors(0.0);
}

bool TeleopCommand::IsFinished(){
	return false;
}

void TeleopCommand::End(){
	drivetrain.get()->Drive(0.0, 0.0);
}

void TeleopCommand::Interrupted(){

}
