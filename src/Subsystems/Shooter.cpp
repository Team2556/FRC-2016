#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter():Subsystem("Shooter"){
	TopBanana = new Servo(TOP_BANANA_SERVO);
	BottomBanana = new Servo(BOTTOM_BANANA_SERVO);
	TopShooter = new CANTalon(TOP_SHOOTER_MOTOR);
	BottomShooter = new CANTalon(BOTTOM_SHOOTER_MOTOR);
	Gimbal = new CANTalon(SHOOTER_GIMBAL);
	Pot = new AnalogPotentiometer(POTENTIOMETER, 360, 15);

	/*LiveWindow *LW = LiveWindow::GetInstance();

	LW->AddActuator("Shooter", "Bottom Banana", BottomBanana);
	LW->AddActuator("Shooter", "Top Banana", TopBanana);*/
}

void Shooter::InitDefaultCommand(){
	//Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Shooter::SetBananas(float TopAngle, float BottomAngle){
	TopBanana->Set(TopAngle);
	BottomBanana->Set(BottomAngle);
}

void Shooter::SetGimbal(float Power){
	Gimbal->Set(Power);
}

void Shooter::SetMotors(float TopPower, float BottomPower){
	TopShooter->Set(TopPower);
	BottomShooter->Set(-BottomPower);
}

float Shooter::getPot(){
	return Pot->Get();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
