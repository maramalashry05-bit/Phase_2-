#include "Load.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <fstream>
#include <iostream>


Load::Load(ApplicationManager* pApp) : Action(pApp)
{
    FileName = "";
}

// Function to get the filename from the user
void Load::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Action: Load Circuit. Enter filename to load from:");
    FileName = pIn->GetSrting(pOut);
    pOut->ClearStatusBar();
}

void Load::Execute()
{
    ReadActionParameters();

    // Check if the user cancelled the input
    if (FileName.empty()) return;

    std::ifstream InFile;
    // Append .txt extension and open the file
    InFile.open(FileName + ".txt", std::ios::in);

    if (!InFile.is_open())
    {
        pManager->GetOutput()->PrintMsg("Error: Could not open file: " + FileName + ".txt");
        return;
    }

    // Clear the existing circuit before loading new components
    pManager->ClearCircuit();

    // Delegate the loading process to the Application Manager
    pManager->LoadAll(InFile);

    InFile.close();
    pManager->GetOutput()->PrintMsg("Circuit loaded successfully from " + FileName + ".txt");
}