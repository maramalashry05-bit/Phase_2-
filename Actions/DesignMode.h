#pragma once
#include "Action.h" 
#include "..\ApplicationManager.h"

// This action simply returns the application to the default design state
class DesignMode : public Action
{
public:
    DesignMode(ApplicationManager* pApp);

    // Reads parameters (None needed for this simple action)
    virtual void ReadActionParameters();

    // Executes the action
    virtual void Execute();

    // Not Undoable
    virtual void Undo();

    // Not Redoable
    virtual void Redo();
};