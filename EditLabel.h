#pragma once
#include "Actions/Action.h"

class EditLabel : public Action {
public:
    EditLabel(ApplicationManager* pApp) : Action(pApp) {}
    void Execute();
    virtual void ReadActionParameters() {}
    virtual void Undo() {}
    virtual void Redo() {}
};