/*
 * IMU.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: Andrew Parmer
 */

#include "IMU.h"

/*AHRS *IMU = new AHRS(SPI::Port::kMXP);
std::mutex IMUMutex;
int IMUAngle;

std::thread StartIMUThread(){
	return std::thread(IMUThread);
}

void IMUThread(){
	std::lock_guard<std::mutex> Lock(IMUMutex);

	IMUAngle = IMUAngle + IMU->GetAngle() * 0.01;

		int Magnitude = std::abs(IMU->GetWorldLinearAccelX()) + std::abs(IMU->GetWorldLinearAccelY()) + std::abs(IMU->GetWorldLinearAccelZ());
		if (Magnitude > 8192 && Magnitude < 32768){
			float AccelVec = atan2f(IMU->GetWorldLinearAccelX(), IMU->GetWorldLinearAccelY()) * 180 / M_PI;
			IMUAngle = 0.98 * IMUAngle + 0.02 * AccelVec;
		}
		std::cout << IMUAngle << std::endl;
}*/

IMU::IMU(SPI::Port Port):AHRS(Port){
	//_DataThread.reset(new std::thread([this](){while(true){this->Thread();}}));
	//_DataThread.get()->detach();
	_DataThread.reset(new std::thread(&IMU::Thread, this));
	_DataThread.get()->detach();
}

int IMU::GetAdjustedAngle(){
	return _AdjustedAngle.load();
}

void IMU::Thread(){
	_AdjustedAngle = _AdjustedAngle + this->GetAngle() * 0.01;

	int Magnitude = std::abs(this->GetWorldLinearAccelX()) + std::abs(this->GetWorldLinearAccelY()) + std::abs(this->GetWorldLinearAccelZ());
	if (Magnitude > 8192 && Magnitude < 32768){
		float AccelVec = atan2f(this->GetWorldLinearAccelX(), this->GetWorldLinearAccelY()) * 180 / M_PI;
		_AdjustedAngle = 0.98 * _AdjustedAngle + 0.02 * AccelVec;
	}
}
