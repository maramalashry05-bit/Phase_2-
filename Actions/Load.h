#pragma once
#include "../Actions/Action.h"
#include <fstream>
#include <string>

class Load : public Action
{
private:
    std::string fileName;
public:
    Load(ApplicationManager* pApp);
    
    virtual void ReadActionParameters() override;
    virtual void Execute() override;
    void Load::Undo() {}
    void Load::Redo() {}
};
