#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <algorithm>

/*inline float VoltageToAngle(float Voltage);
inline float AngleToVoltage(float Angle);*/

class Shooter:public Subsystem{
private:
	Servo *TopBanana;
	Talon *BottomBanana, *LEDLight;
	DigitalInput *UpperLimit, *LowerLimit;
	float SetPointStep;
	float Ang;
public:
	CANTalon *TopShooter, *BottomShooter, *Gimbal;
	PIDController *PID;
	AnalogPotentiometer *Pot;
	Shooter();
	void InitDefaultCommand();
	void SetBananas(float TopAngle, float BottomPower);
	void SetGimbal(float Power);
	void SetMotors(float TopPower, float BottomPower);
	void AutoShoot(float Scale);
	void ResetPID();
	void SetAngle(float Angle);
	float GetAngle();
	void SetLEDs(float Intensity);
};

#endif
