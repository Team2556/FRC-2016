#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter():Subsystem("Shooter"){
	TopBanana = new Servo(TOP_BANANA_SERVO);
	BottomBanana = new Servo(BOTTOM_BANANA_SERVO);
	TopShooter = new CANTalon(TOP_SHOOTER_MOTOR);
	BottomShooter = new CANTalon(TOP_SHOOTER_MOTOR);

	LiveWindow *LW = LiveWindow::GetInstance();
	LW->AddActuator("Shooter", "Servo1", TopBanana);
}

void Shooter::InitDefaultCommand(){
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Shooter::SetBananas(int TopAngle, int BottomAngle){
	TopBanana->SetAngle(TopAngle);
	BottomBanana->SetAngle(BottomAngle);
}

void Shooter::SetAngle(int Angle){

}

void Shooter::Load(){

}

void Shooter::Shoot(int Power){

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
