#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "IMU.h"
#include <unistd.h>

#include "Commands/Autonomous/AutonomousMain.h"
#include "Commands/Teleoperated/TeleopCommand.h"

IMU *NavX;

class Robot:public IterativeRobot{
private:
	Preferences *Prefs;
	AutonomousMain *AutonomousC;
	TeleopCommand *TeleopC;
	//std::shared_ptr<USBCamera> Camera;

	void RobotInit(){
		CommandBase::init();
		NavX = new IMU(SPI::Port::kMXP);
		Prefs = Preferences::GetInstance();
		AutonomousC = new AutonomousMain();
		TeleopC = new TeleopCommand();

		CameraServer::GetInstance()->StartAutomaticCapture();

		/*if (fork() == 0){
			system("/home/lvuser/grip &");
		}*/
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit(){
		CommandBase::shooter.get()->ResetPID();
	}

	void DisabledPeriodic(){
		Scheduler::GetInstance()->Run();
		GlobalPeriodic();
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
		if (AutonomousC != NULL && Prefs->GetBoolean("Auto", false))
			AutonomousC->Start();

		//CameraServer::GetInstance()->StartAutomaticCapture("cam1");
		/*Camera->SetBrightness(30);
		Camera->SetExposureManual(0);*/
		GlobalInit();
	}

	void AutonomousPeriodic(){
		Scheduler::GetInstance()->Run();
		GlobalPeriodic();
	}

	void TeleopInit(){
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (AutonomousC != NULL)
			AutonomousC->Cancel();
		if(TeleopC != NULL)
			TeleopC->Start();
		GlobalInit();
	}

	void TeleopPeriodic(){
		Scheduler::GetInstance()->Run();
		GlobalPeriodic();
	}

	void TestPeriodic(){
		LiveWindow::GetInstance()->Run();
		GlobalPeriodic();
		if(TeleopC != NULL)
			TeleopC->Start();
	}

	void GlobalInit(){
		/*CommandBase::shooter.get()->PID->Enable();
		CommandBase::shooter.get()->SetLEDs(0.10);*/
	}

	void GlobalPeriodic(){
		SmartDashboard::PutNumber("Raw Angle (yaw)", NavX->GetAngle());
		/*SmartDashboard::PutNumber("Shooter Angle", CommandBase::shooter.get()->GetAngle());
		SmartDashboard::PutNumber("Shooter Value", CommandBase::shooter.get()->Gimbal->Get());*/
		SmartDashboard::PutNumber("IMU Angle", NavX->GetYaw());

		//CommandBase::shooter.get()->PID->SetPID(Prefs->GetDouble("kP", 0.0), Prefs->GetDouble("kI", 0.0), Prefs->GetDouble("kD", 0.0), Prefs->GetDouble("kF", 0.0));
		//shooter.get()->SetGimbal(0.07);
		//AutonomousC->PID->SetPID(Prefs->GetDouble("kP", 0.0), Prefs->GetDouble("kI", 0.0), Prefs->GetDouble("kD", 0.0), Prefs->GetDouble("kF", 0.0));
		//AutonomousC.get()->SetAngle(Prefs->GetDouble("SetPoint", 0.0));
		//CommandBase::shooter.get()->Gimbal->SetCloseLoopRampRate(Prefs->GetDouble("Ramp Rate", 0.0));

		//CommandBase::shooter.get()->SetAngle(Prefs->GetDouble("Setpoint", 0.0));

		/*AutonomousC->AlignC->PID->SetPID(Prefs->GetDouble("kP", 0.0), Prefs->GetDouble("kI", 0.0), Prefs->GetDouble("kD", 0.0));
		AutonomousC->AlignC->PID->SetSetpoint(Prefs->GetDouble("Setpoint", 0.0));*/
	}
};

START_ROBOT_CLASS(Robot)

