#include "OI.h"
#include "WPILib.h"
OI::OI()
{
	// Process operator interface input here.
	leftjoy = new  Joystick(0);
	rightjoy = new Joystick(1);
	gamecon = new Joystick(2);
	buttonleft = new JoystickButton(leftjoy, 1);
	buttonright = new JoystickButton(rightjoy, 1);
	buttonleftf = new JoystickButton(leftjoy, 4);
	buttonrightf = new JoystickButton(rightjoy, 5);

	button1 = new JoystickButton(gamecon, 1);
	button2 = new JoystickButton(gamecon, 2);
	button3 = new JoystickButton(gamecon, 3);
	button4 = new JoystickButton(gamecon, 4);

	buttonforwardl = new JoystickButton(leftjoy, 3);
	buttonbackwardl = new JoystickButton(leftjoy, 2);
	buttonforwardr = new JoystickButton(rightjoy, 3);
	buttonbackwardr = new JoystickButton(rightjoy, 2);
	buttonsl = new JoystickButton(leftjoy, 5);
	buttonsr = new JoystickButton(rightjoy, 4);

}

	Joystick* OI::GetLeftjoy() {
		return leftjoy;
	}
	Joystick* OI::GetRightjoy() {
		return rightjoy;
	}
JoystickButton* OI::GetButtonLeft()
{
	return buttonleft;
}
JoystickButton* OI::GetButtonRight()
{
	return buttonright;
}
JoystickButton* OI::GetButtonLeftf()
{
	return buttonleftf;
}
JoystickButton* OI::GetButtonRightf()
{
	return buttonrightf;
}
Joystick* OI::GetGameCon()
{
	return gamecon;
}
JoystickButton* OI::GetButton1()
{
	return button1;
}
JoystickButton* OI::GetButton2()
{
	return button2;
}
JoystickButton* OI::GetButton3()
{
	return button3;
}
JoystickButton* OI::GetButton4()
{
	return button4;
}
JoystickButton* OI::GetButtonFl()
{
	return buttonforwardl;
}
JoystickButton* OI::GetButtonFr()
{
	return buttonforwardr;
}
JoystickButton* OI::GetButtonBl()
{
	return buttonbackwardl;
}
JoystickButton* OI::GetButtonBr()
{
	return buttonbackwardr;
}
JoystickButton* OI::GetButtonSl()
{
	return buttonsl;
}
JoystickButton* OI::GetButtonSr()
{
	return buttonsr;
}


