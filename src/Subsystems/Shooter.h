#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

enum TopBananaAngle{
	Top_Banana_Open,
	Top_Banana_Lock,
	Top_Banana_Closed
};

enum BottomBananaAngle{
	Bottom_Banana_Open,
	Bottom_Banana_Closed
};

class Shooter:public Subsystem{
private:
	Servo *TopBanana, *BottomBanana;
	CANTalon *TopShooter, *BottomShooter;
	// Motors for angling shooter
public:
	Shooter();
	void InitDefaultCommand();
	void SetBananas(int TopAngle, int BottomAngle);
	void SetAngle(int Angle);
	void SetMotors(float TopPower, float BottomPower);
};

#endif
