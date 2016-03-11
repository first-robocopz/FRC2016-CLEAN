#pragma once

#include "OI.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/ShootPlatform.h"

#include <Buttons/JoystickButton.h>
#include <Commands/Command.h>

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase : public Command {
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
    static DriveTrain *drivetrain;
	static OI *oi;
	static ShootPlatform *shootplatform;
};
