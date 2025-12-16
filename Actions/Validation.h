#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

class Validation : public Action
{
public:
	Validation(ApplicationManager* pApp);
	virtual ~Validation();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};