/*
 * IMU.h
 *
 *  Created on: Feb 6, 2016
 *      Author: Andrew Parmer
 */

#ifndef SRC_IMU_H_
#define SRC_IMU_H_

#include <AHRS.h>
#include <atomic>
#include <cmath>
#include <math.h>

class IMU:public AHRS{
	private:
		std::unique_ptr<std::thread> _DataThread;
		std::atomic<float> _AdjustedAngle;
	public:
		IMU(SPI::Port Port);
		int GetAdjustedAngle();
		void Thread();
};

#endif /* SRC_IMU_H_ */
