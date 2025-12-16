#include "Load.h"
#include "../ApplicationManager.h"
#include "../gui/input.h"
#include "../gui/output.h"
#include <fstream>
#include <iostream>

std::string filename;
Load::Load(ApplicationManager* papp) : Action(papp)
{
    filename = "";
}

// function to get the filename from the user
void Load::ReadActionParameters()
{
    Output* pout = pManager->GetOutput();
    Input* pin = pManager->GetInput();

    pout->PrintMsg("action: load circuit. enter filename to load from:");
    filename = pin->GetSrting(pout);
    pout->ClearStatusBar();
}

void Load::Execute()
{
    ReadActionParameters();

    // check if the user cancelled the input
    if (filename.empty()) return;

    std::ifstream infile;
    // append .txt extension and open the file
    infile.open(filename + ".txt", std::ios::in);

    if (!infile.is_open())
    {
        pManager->GetOutput()->PrintMsg("error: could not open file: " + filename + ".txt");
        return;
    }

    // clear the existing circuit before loading new components
    pManager->ClearCircuit();

    // delegate the loading process to the application manager
    pManager->LoadAll(infile);

    infile.close();
    pManager->GetOutput()->PrintMsg("circuit loaded successfully from " + filename + ".txt");}