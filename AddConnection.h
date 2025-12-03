#pragma once
#include "Actions\action.h"
#include "Components\Connection.h"
class ActionAddConnection : public Action
{
private:
    Component* SrcComp;    // Source gate
    Component* DstComp;    // Destination gate
    int SrcPinIndex;       // Usually 0 for gates with single output
    int DstPinIndex;       // Input pin number (0 or 1 or 3)
    GraphicsInfo GInfo;    // Connection line info

public:
    ActionAddConnection(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo() ;
    virtual void Redo() ;
};

