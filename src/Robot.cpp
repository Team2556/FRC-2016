#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "IMU.h"

#include "Commands/Autonomous/AutonomousMain.h"
#include "Commands/Teleoperated/TeleopCommand.h"

IMU *NavX = new IMU(SPI::Port::kMXP);

class Robot:public IterativeRobot{
private:
	AutonomousMain *AutonomousC= new AutonomousMain();
	TeleopCommand *TeleopC = new TeleopCommand();

	void RobotInit(){
		CommandBase::init();
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit(){
	}

	void DisabledPeriodic(){
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit(){
		if (AutonomousC != NULL)
			AutonomousC->Start();
	}

	void AutonomousPeriodic(){
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit(){
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		/*if (autonomousCommand != NULL)
			autonomousCommand->Cancel();*/
		if(TeleopC != NULL)
			TeleopC->Start();
	}

	void TeleopPeriodic(){
		Scheduler::GetInstance()->Run();

		if(NavX != NULL){
			std::cout << "Adjusted Angle: " << NavX->GetAdjustedAngle() << std::endl;
			std::cout << "Angle: " << NavX->GetAngle() << std::endl;
		}
	}

	void TestPeriodic(){
		LiveWindow::GetInstance()->Run();
		if(TeleopC != NULL)
			TeleopC->Start();
	}
};

START_ROBOT_CLASS(Robot)

