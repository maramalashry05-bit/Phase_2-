#pragma once
#include "Actions/Action.h"

class Copy : public Action
{
public:
    Copy(ApplicationManager* pApp);

    virtual void Execute();

    virtual void ReadActionParameters() {}
    virtual void Undo() {}
    virtual void Redo() {}
};
#pragma once
