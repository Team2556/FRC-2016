#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter():Subsystem("Shooter"){
	TopBanana = new Servo(TOP_BANANA_SERVO);
	BottomBanana = new Talon(BOTTOM_BANANA_TALON);
	TopShooter = new CANTalon(TOP_SHOOTER_MOTOR);
	BottomShooter = new CANTalon(BOTTOM_SHOOTER_MOTOR);
	Gimbal = new CANTalon(SHOOTER_GIMBAL);

	UpperLimit = new DigitalInput(BOTTOM_BANNANA_UPPER_LIMIT);
	SmartDashboard::PutNumber("Gimbal", Gimbal->Get());
	LowerLimit = new DigitalInput(BOTTOM_BANNANA_LOWER_LIMIT);

	LEDLight = new Talon(VISION_LEDS);

	Pot = new AnalogPotentiometer(POTENTIOMETER, 270, -24);

	//PID = new PIDController(0.025, 0.00000185, 0.0, 0.0, Pot, Gimbal, 0.02);
	PID = new PIDController(0.0, 0.0, 0.0, 0.0, Pot, Gimbal, 0.02);

	SetPointStep = 0.1;
	Ang = 90.0;

	//Gimbal->SetControlMode(CANSpeedController::kPosition);
	//Gimbal->SetFeedbackDevice(CANTalon::AnalogPot);
}

void Shooter::InitDefaultCommand(){

}

void Shooter::SetBananas(float TopAngle, float BottomPower){
	TopBanana->Set(TopAngle);
	BottomBanana->Set((!(LowerLimit->Get()) && (BottomPower > 0.1) ? -(BottomPower / 2) : (!(UpperLimit->Get()) && !(BottomPower > 0.1) ? 0.5 : 0.0)));

	SmartDashboard::PutNumber("BottomPower", BottomPower);
	SmartDashboard::PutBoolean("Lower Limit", LowerLimit->Get());
	SmartDashboard::PutBoolean("Upper Limit", UpperLimit->Get());
}

void Shooter::SetGimbal(float Power){
	Gimbal->Set(Power);
}

void Shooter::SetMotors(float TopPower, float BottomPower){
	TopShooter->Set(TopPower);
	BottomShooter->Set(BottomPower);
}

void Shooter::AutoShoot(float Scale){
	float dist = cos(Pot->Get()) * Scale;

	float speed = sqrt(pow(6.913222, 2) + pow(dist / 0.70543, 2));
	float angle = tan(6.913222 / (dist / 0.70543));

	//set motor speed and gimbal angle
	SmartDashboard::PutNumber("Speed", speed);
	SmartDashboard::PutNumber("Angle", angle);
}

void Shooter::ResetPID(){
	PID->Reset();
}

void Shooter::SetAngle(float Angle){
	PID->SetPID((Angle * SmartDashboard::GetNumber("PWeight", 0.0)) + SmartDashboard::GetNumber("PBias", 0.0), (Angle * SmartDashboard::GetNumber("IWeight", 0.0)) + SmartDashboard::GetNumber("IBias", 0.0), Angle * SmartDashboard::GetNumber("DWeight", 0.0), 0);
	PID->SetSetpoint(Angle);// - PID->GetSetpoint() > SetPointStep ? PID->GetSetpoint() + SetPointStep * ((Angle - PID->GetSetpoint()) / abs(Angle - PID->GetSetpoint())) : Angle);

	Ang = Angle;
}

float Shooter::GetAngle(){
	//return VoltageToAngle(Gimbal->GetAnalogInRaw());
	return Pot->Get();
}

/*inline float VoltageToAngle(float Voltage){
	return (Voltage - 150) / 5.6;
}

inline float AngleToVoltage(float Angle){
	return (Angle * 5.6) + 150;
}*/


void Shooter::SetLEDs(float Intensity){
	LEDLight->Set(Intensity);
}
