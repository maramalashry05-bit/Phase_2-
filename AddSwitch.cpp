#include "AddSwitch.h"
#include "ApplicationManager.h"
#include "Switch.h"

AddSwitch::AddSwitch(ApplicationManager* pApp)
    : Action(pApp)
{
}

AddSwitch::~AddSwitch()
{
}

void AddSwitch::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->ClearStatusBar();
    pOut->PrintMsg("Click to add a switch");

    pIn->GetPointClicked(x, y);

    pOut->ClearStatusBar();
}

void AddSwitch::Execute()
{
    // 1?? Read user click
    ReadActionParameters(); // sets x, y

    // 2?? Calculate rectangle corners
    int Len = UI.SWITCH_Width;
    int Wdth = UI.SWITCH_Height;



    GraphicsInfo GInfo;

    GInfo.x1 = x - Len / 2;
    GInfo.x2 = x + Len / 2;
    GInfo.y1 = y - Wdth / 2;
    GInfo.y2 = y + Wdth / 2;


    Component* overlap = pManager->GetOverlap(GInfo.x1, GInfo.y1, GInfo.x2, GInfo.y2);
    if (overlap)
    {
        // Highlight the overlapped component
        overlap->Setselected(true);

        // Show message to user
        pManager->GetOutput()->PrintMsg("Cannot place component here (overlap)");

        return; // Stop execution
    }

    // Optional: unselect any previously selected components
    pManager->unselectAll();

    // Create switch
    Switch* pSw = new Switch(GInfo);  // uses GraphicsInfo constructor
   

    //  Add to application manager
    pManager->AddComponent(pSw);

    //  Update GUI
    pManager->UpdateInterface();

}

void AddSwitch::Undo()
{

}

void AddSwitch::Redo()
{

}