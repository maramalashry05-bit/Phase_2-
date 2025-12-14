#include "SelectAction.h"
#include "Switch.h"

SelectAction::SelectAction(ApplicationManager* pApp) : Action(pApp) 
{
}

SelectAction::~SelectAction(void)
{
}

void SelectAction::ReadActionParameters()
{
    //Get a Pointer to the Input / Output Interfaces
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    

   
    //Clear Status Bar
    pOut->ClearStatusBar();
    // Print action Message
    pOut->PrintMsg("Click to select / unselect components. Click empty area to clear selection.");

    //Wait for User Input
    pIn->GetPointClicked(x, y);

}

void SelectAction::Execute()
{
    ReadActionParameters();

    Component* comp = pManager->GetComponentAt(x, y);
    Output* pOut = pManager->GetOutput();

    if (comp != nullptr)
    {
        if (comp->Getselected())
        {
            // toggle OFF
            pManager->UnselectComponent(comp);
            pOut->PrintMsg("Component unselected");
        }
        else
        {
            // toggle ON (add to selection)
            pManager->SetSelectedComponent(comp);
            pOut->PrintMsg("Component selected");

            if (!comp->isLapelEmp())
            {
                std::string msg = "Label : " + comp->GetLabel();
                pOut->PrintMsg(msg);
            }
        }
    }
    else
    {
        // empty area ? unselect all
        pManager->unselectAll();
        pOut->PrintMsg("Clicked empty area, all components unselected");
    }

    pManager->UpdateInterface();
    Switch* pSw = dynamic_cast<Switch*>(comp);
    if (pSw)
    {
        pSw->Toggle();
    }

}
void SelectAction::Undo()
{

}
void SelectAction::Redo()
{

}