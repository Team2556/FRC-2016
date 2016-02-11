/*
 * IMU.h
 *
 *  Created on: Feb 6, 2016
 *      Author: Andrew Parmer
 */

#ifndef SRC_IMU_H_
#define SRC_IMU_H_

#include <AHRS.h>

/*class IMU:public AHRS{
	private:
		std::unique_ptr<AHRS> _IMU;
		std::unique_ptr<std::thread> _DataThread;

		int _Angle = 0;
		int _LinearAccel[3];
	public:
		IMU();
		int GetAdjustedAngle();
		//void Thread();
};*/

#endif /* SRC_IMU_H_ */
