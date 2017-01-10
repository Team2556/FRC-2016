#include "Drive.h"

Drive::Drive(){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivetrain.get());
	Requires(shooter.get());
	SetTimeout(2);
}

// Called just before this Command runs the first time
void Drive::Initialize(){

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute(){
	drivetrain.get()->Drive(1.0, 0.0);
	shooter.get()->SetGimbal(0.2);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished(){
	return IsTimedOut();
}

// Called once after isFinished returns true
void Drive::End(){
	drivetrain.get()->Drive(0.0, 0.0);
	shooter.get()->SetGimbal(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted(){

}
