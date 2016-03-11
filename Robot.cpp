#include "Commands/Command.h"
#include "Commands/MoveForward.h"
#include "CommandBase.h"
#include "RobotMap.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/ShootPlatform.h"

#include <WPILib.h>

class Robot : public IterativeRobot {
private:
	//SendableChooser *autoChooser;
	DriveTrain *drivetrain;
	OI *oi;
	ShootPlatform *shootplatform;

	BuiltInAccelerometer *accel;
	Command *autonomousCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		CommandBase::init();
		SmartDashboard::init();
		//SmartDashboard::PutData(drivetrain);
		//autoChooser = new SendableChooser();
		//autoChooser->AddDefault("Default program", new  DriveForward());
		//autoChooser->AddObject("Difficult Mode", new PickupAuto());
		//SmartDashboard::PutData("Autonomous modes", autoChooser);

		lw = LiveWindow::GetInstance();
		CameraServer::GetInstance()->SetQuality(30);
		CameraServer::GetInstance()->StartAutomaticCapture("cam1");
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();

	}

	void AutonomousInit()
	{
		//autonomousCommand = (Command *) autoChooser->GetSelected();
		autonomousCommand = new MoveForward();
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
		Log();
	}

	void TeleopInit()
	{
		/*SmartDashboard::PutNumber("Forward Button Speed", forwardrate);
		SmartDashboard::PutNumber("Backwards Button Speed", backwardrate);
		SmartDashboard::PutNumber("Turn Buttons Slow Speed", turnRate);
		SmartDashboard::PutNumber("Turn Buttons Fast Speed", turnRatef);
		SmartDashboard::PutNumber("Slide Button Speed", slideRate);*/
		SmartDashboard::PutNumber("Firing flywheel power, 0 to 1", 1.0f);
		SmartDashboard::PutNumber("Firing flywheel differential, 0 to 1", 1.0f);
		SmartDashboard::PutNumber("Loading servo power, 0 to 1", 0.5f);

		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();


	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		Log();
		lw->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
		Log();
	}

	void Log()
	{

	}
};

START_ROBOT_CLASS(Robot);

