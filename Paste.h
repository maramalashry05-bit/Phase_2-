#pragma once
#include "Actions/Action.h"

class Paste : public Action
{
public:
    Paste(ApplicationManager* pApp);

    virtual void Execute();

    virtual void ReadActionParameters() {}
    virtual void Undo() {}
    virtual void Redo() {}
};
