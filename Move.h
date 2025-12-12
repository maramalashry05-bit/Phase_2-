#pragma once
#include "Actions/Action.h"

class Move : public Action
{
public:
    Move(ApplicationManager* pApp);
    virtual void Execute();
    virtual void ReadActionParameters() {}
    virtual void Undo() {}
    virtual void Redo() {}
};
