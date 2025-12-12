#pragma once
#include "Actions/Action.h"

class AddLabel : public Action {
public:
    AddLabel(ApplicationManager* pApp) : Action(pApp) {}
    void Execute();
    virtual void ReadActionParameters() {}
    virtual void Undo() {}
    virtual void Redo() {}
};