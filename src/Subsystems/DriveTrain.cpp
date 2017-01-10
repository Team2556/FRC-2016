#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain():Subsystem("DriveTrain"){
	FrontLeft = new CANTalon(FRONT_LEFT_MOTOR);
	FrontRight = new CANTalon(FRONT_RIGHT_MOTOR);
	BackLeft = new CANTalon(BACK_LEFT_MOTOR);
	BackRight = new CANTalon(BACK_RIGHT_MOTOR);

	BackLeft->SetControlMode(CANSpeedController::kFollower);
	BackLeft->Set(FRONT_LEFT_MOTOR);

	BackRight->SetControlMode(CANSpeedController::kFollower);
	BackRight->Set(FRONT_RIGHT_MOTOR);
}

void DriveTrain::InitDefaultCommand(){

}

void DriveTrain::Drive(float Power, float Rotation){
	FrontLeft->Set(Power + Rotation);

	FrontRight->Set(-(Power - Rotation));
}

void DriveTrain::PIDWrite(float Output){
	Drive(0.0, Output);
}
