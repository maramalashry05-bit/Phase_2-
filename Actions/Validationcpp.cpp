#include "Validation.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h" 

Validation::Validation(ApplicationManager* pApp) : Action(pApp)
{
}

Validation::~Validation()
{
}

void Validation::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();

    // Display message to the user before starting the validation
    pOut->PrintMsg("Circuit Validation Mode: Checking all components for proper connections...");
}

void Validation::Execute()
{
    ReadActionParameters();
    // The core logic is calling the manager's validation function
    pManager->ValidateCircuit();
    // The ValidateCircuit() function itself prints the success/failure message.
}
void Validation::Undo()
{
    // Validation action is not undoable
}

void Validation::Redo()
{
    // Validation action is not redoable
}