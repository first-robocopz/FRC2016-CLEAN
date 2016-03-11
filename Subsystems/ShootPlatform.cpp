#include "ShootPlatform.h"

#include "../RobotMap.h"
#include "../Commands/Shoot.h"

#include <SmartDashboard/SmartDashboard.h>
#include <Talon.h>

#include <algorithm>

ShootPlatform::ShootPlatform() :
Subsystem("ShootPlatform") {
	shootforward = new Talon(ShootForward);
	shootback = new Talon(ShootBack);
	servoleft = new Servo(ServoLeft);
	servoright = new Servo(ServoRight);

}

void ShootPlatform::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Shoot());
}

void ShootPlatform::ShootOI(JoystickButton* button1, JoystickButton* button2, JoystickButton* button3, JoystickButton* button4) {
	float power = SmartDashboard::GetNumber("Firing flywheel power, 0 to 1", 1.0f);
	float differential = SmartDashboard::GetNumber("Firing flywheel differential, 0 to 1", 1.0f);
	float pow_f = std::min<float>(power * differential * 2, 1);
	float pow_b = std::min<float>(power * (1-differential) * 2, 1);

	if(button4->Get()){
		shootback->Set(-.5);
	} else if (button2->Get()){
		shootforward->Set(pow_f);
		shootback->Set(-pow_b);
	} else {
		shootforward->Set(0.0);
		shootback->Set(0.0);
	}

    if(button1->Get()) {
		servoleft->Set(1.0);
		servoright->Set(1.0);
	} else if (button3->Get()) {
		servoleft->Set(0.0);
		servoright->Set(0.0);
	} else {
		servoleft->Set(SmartDashboard::GetNumber("Loading servo power", 0.5f));
		servoright->Set(SmartDashboard::GetNumber("Loading servo power", 0.5f));
	}
}
