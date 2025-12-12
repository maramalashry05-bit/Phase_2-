#pragma once
#include "Actions/Action.h"

class Delete : public Action
{
public:
    Delete(ApplicationManager* pApp);
    virtual void Execute();
    virtual void ReadActionParameters() {}
    virtual void Undo() {}
    virtual void Redo() {}
};
#pragma once
