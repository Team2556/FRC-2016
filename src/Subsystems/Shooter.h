#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

enum TopBananaAngle{
	Top_Banana_Open,
	Top_Banana_Closed
};

enum BottomBananaAngle{
	Bottom_Banana_Open,
	Bottom_Banana_Closed
};

class Shooter:public Subsystem{
private:
	Servo *TopBanana, *BottomBanana;
	CANTalon *TopShooter, *BottomShooter, *Gimbal;
public:
	Shooter();
	void InitDefaultCommand();
	void SetBananas(float TopAngle, float BottomAngle);
	void SetGimbal(float Power);
	void SetMotors(float TopPower, float BottomPower);
};

#endif
