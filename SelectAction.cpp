#include "SelectAction.h"

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

    //Print Action Message
    pOut->PrintMsg("Select a component");

    //Wait for User Input
    pIn->GetPointClicked(x, y);

    //Clear Status Bar
    pOut->ClearStatusBar();

}

void SelectAction::Execute()
{
    // Read where user clicked
    ReadActionParameters();

    // Check if a component exists at that point
    Component* comp = pManager->GetComponentAt(x, y);
    Output* pOut = pManager->GetOutput();

    if (comp != NULL)
    {
        // Ensure only one component is selected
        pManager->unselectAll();
        // Select this component and inform ApplicationManager
        comp->Setselected(true);
        
        if(!comp->isLapelEmp()){
        std::string msg = std::string("Label : ") + comp->GetLabel();
        pOut->PrintMsg(msg);
        }
        
        pManager->SetSelectedComponent(comp);
    }
    else
    {
        // Clicked empty area ? unselect all and clear selected pointer
        pManager->unselectAll();
        pManager->SetSelectedComponent(nullptr);
    }

    // Redraw GUI to show selection highlight
    pManager->UpdateInterface();
}
void SelectAction::Undo()
{

}
void SelectAction::Redo()
{

}