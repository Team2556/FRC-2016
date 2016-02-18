/*
 * IMU.h
 *
 *  Created on: Feb 6, 2016
 *      Author: Andrew Parmer
 */

#ifndef SRC_IMU_H_
#define SRC_IMU_H_

#include <AHRS.h>
#include <thread>
#include <mutex>
#include <cmath>
#include <math.h>

/*std::thread StartIMUThread();
void IMUThread();*/

class IMU:public AHRS{
	private:
		std::unique_ptr<std::thread> _DataThread;
		std::atomic<float> _AdjustedAngle;
		//std::thread StartThread();
		void Thread();
	public:
		IMU(SPI::Port Port);
		int GetAdjustedAngle();
};

#endif /* SRC_IMU_H_ */
