#pragma once
#include "Actions\Action.h"
#include "ApplicationManager.h"

class EditConnection : public Action
{
public:
    EditConnection(ApplicationManager* pApp) : Action(pApp) {}
    void Execute();
    virtual void ReadActionParameters() {}
    virtual void Undo() {}
    virtual void Redo() {}

};
