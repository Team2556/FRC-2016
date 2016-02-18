#include "AlignToGoal.h"
/*
AlignToGoal::AlignToGoal():PIDCommand("Goal Alignment", 1.0, 0.0, 0.0, 0.0){
	Requires(CommandBase::drivetrain.get());

	_Table = NetworkTable::GetTable("GRIP/VisionTarget");

	this->SetSetpoint(50.0);
}

double AlignToGoal::ReturnPIDInput(){
	return _Table->GetNumber("centerX", 0.0);
}

void AlignToGoal::UsePIDOutput(double Value){
	CommandBase::drivetrain.get()->Drive(0.0, Value);
}

void AlignToGoal::Initialize(){

}

void AlignToGoal::Execute(){

}

bool AlignToGoal::IsFinished(){
	return false;
}

void AlignToGoal::End(){

}

void AlignToGoal::Interrupted(){

}*/
