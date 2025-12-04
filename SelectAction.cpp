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

    if (comp != NULL)
    {
        
        // Select this component
        comp->Setselected(true);
    }
    else
    {
        // Clicked empty area ? deselect all
        pManager->unselectAll();
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