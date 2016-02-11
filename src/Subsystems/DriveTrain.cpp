#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain():Subsystem("DriveTrain"){
	FrontLeft = new CANTalon(FRONT_LEFT_MOTOR);
	FrontRight = new CANTalon(FRONT_RIGHT_MOTOR);
	BackLeft = new CANTalon(BACK_LEFT_MOTOR);
	BackRight = new CANTalon(BACK_RIGHT_MOTOR);
}

void DriveTrain::InitDefaultCommand(){
	//SetDefaultCommand(new SkidDrive());
}

void DriveTrain::Drive(float Power, float Rotation){
	FrontLeft->Set(Power + Rotation);
	BackLeft->Set(Power + Rotation);

	FrontRight->Set(-(Power - Rotation));
	BackRight->Set(-(Power - Rotation));
}
