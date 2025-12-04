#ifndef SELECTACTION_H
#define SELECTACTION_H

#include "Actions\Action.h"
#include "ApplicationManager.h"

class SelectAction : public Action
{
private:
    int x, y; // click coordinates
public:
    SelectAction(ApplicationManager* pApp);
    virtual ~SelectAction(void);
    //Reads parameters required for action to execute
    virtual void ReadActionParameters();

    //Execute action (code depends on action type)
   virtual void Execute();
   virtual void Undo();
   virtual void Redo();
};

#endif

