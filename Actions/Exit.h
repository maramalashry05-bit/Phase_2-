#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class Exit : public Action
{
public:
	Exit(ApplicationManager* pApp);
	virtual ~Exit(void);
	virtual void ReadActionParameters();
	virtual void Execute();

};

