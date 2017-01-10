#include "AlignToGoal.h"

AlignToGoal::AlignToGoal(){
	Requires(drivetrain.get());

	PID = new PIDController(0.0, 0.0, 0.0, NavX, drivetrain.get(), 0.02);

	//this->SetSetpoint(50.0);
}

/*double AlignToGoal::ReturnPIDInput(){
	return _Table->GetNumber("centerX", 0.0);
}

void AlignToGoal::UsePIDOutput(double Value){
	CommandBase::drivetrain.get()->Drive(0.0, Value);
}*/

void AlignToGoal::Initialize(){
	PID->Enable();
}

void AlignToGoal::Execute(){

}

bool AlignToGoal::IsFinished(){
	return false;
}

void AlignToGoal::End(){
	PID->Disable();
}

void AlignToGoal::Interrupted(){
	PID->Disable();
}
