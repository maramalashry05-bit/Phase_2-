#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

class Probing : public Action
{

private:
    int Cx, Cy;

public:
    Probing(ApplicationManager* pApp);

    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo();
    virtual void Redo();
};

