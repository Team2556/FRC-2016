/*
 * IMU.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: Andrew Parmer
 */

#include "IMU.h"

IMU::IMU(SPI::Port Port):AHRS(Port){
	_DataThread.reset(new std::thread([this](){while(true){this->Thread();}}));
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

