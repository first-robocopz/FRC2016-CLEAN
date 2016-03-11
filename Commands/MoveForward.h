#pragma once

#include "../CommandBase.h"

class MoveForward: public CommandBase
{
public:
	MoveForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
