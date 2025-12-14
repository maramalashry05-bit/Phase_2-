#pragma once
#include "Actions/Action.h"

class Cut : public Action
{
public:
    Cut(ApplicationManager* pApp);

    virtual void Execute();

    // Cut does not need additional parameters
    virtual void ReadActionParameters() {}

    // Optional: implement Undo/Redo if you want
    virtual void Undo() {}
    virtual void Redo() {}
};

