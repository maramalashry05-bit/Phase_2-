#ifndef ADDCONNECTIONACTION_H
#define ADDCONNECTIONACTION_H

#include "Actions\Action.h"
#include "ApplicationManager.h"

class AddConnection : public Action
{
private:
	int x1, y1, x2, y2;


public:
	AddConnection(ApplicationManager* pApp);

	~AddConnection(void);
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif
