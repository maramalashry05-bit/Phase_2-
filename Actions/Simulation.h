#pragma once
#include "Action.h"

class Simulation : public Action
{
public:
    Simulation(ApplicationManager* pApp);

    // Reads parameters (if any) before execution
    virtual void ReadActionParameters() override;

    // Executes the simulation setup and propagation
    virtual void Execute() override;

    // Simulation typically doesn't need Undo/Redo
    virtual void Undo() override {}
    virtual void Redo() override {}
};