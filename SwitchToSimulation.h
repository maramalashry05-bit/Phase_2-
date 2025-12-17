#pragma once

#include "Actions/Action.h"

class ApplicationManager; // forward declaration

class SwitchToSimulation : public Action
{
public:
    SwitchToSimulation(ApplicationManager* pApp);
    virtual ~SwitchToSimulation() {}

    virtual void ReadActionParameters();
    virtual void Execute();

    virtual void Undo();
    virtual void Redo();
};
