#include "AddConnection.h"
#include "Components\Connection.h"
#include "Components\Component.h"

AddConnection::AddConnection(ApplicationManager* pApp)
    : Action(pApp), x1(0), y1(0), x2(0), y2(0)
{
}

AddConnection::~AddConnection(void)
{
}


void AddConnection::ReadActionParameters()
{
    //Get a Pointer to the Input / Output Interfaces
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();


    // 1? Get source click
    pOut->PrintMsg("Click on the source gate (output pin)...");
    pIn->GetPointClicked(x1, y1);

    // 2? Get destination click
    pOut->PrintMsg("Click on the destination gate (input pin)...");
    pIn->GetPointClicked(x2, y2);

    pOut->ClearStatusBar();
}

void AddConnection::Execute()
{
    ReadActionParameters();
    Output* pOut = pManager->GetOutput();
    // Lookup source component
    Component* srcComp = pManager->GetComponentAt(x1, y1);
    if (!srcComp || !srcComp->GetOutputPin())
    {
        pOut->PrintMsg("Invalid source component. Connection canceled.");
        return;
    }
    OutputPin* srcPin = srcComp->GetOutputPin();

    // Lookup destination component
    Component* dstComp = pManager->GetComponentAt(x2, y2);
    if (!dstComp || !dstComp->GetInputPin(1))
    {
        pOut->PrintMsg("Invalid destination component. Connection canceled.");
        return;
    }
    InputPin* dstPin = dstComp->GetInputPin(1);

    // Compute connection line coordinates from GraphicsInfo
    GraphicsInfo gfxConn;
    GraphicsInfo srcGfx = srcComp->GetGraphicsInfo();
    GraphicsInfo dstGfx = dstComp->GetGraphicsInfo();

    gfxConn.x1 = srcGfx.x2;
    gfxConn.y1 = (srcGfx.y1 + srcGfx.y2) / 2;
    gfxConn.x2 = dstGfx.x1;
    gfxConn.y2 = (dstGfx.y1 + dstGfx.y2) / 2;
    //Component* overlap = pManager->GetOverlap(gfxConn.x1, gfxConn.y1, gfxConn.x2, gfxConn.y2);
    //if (overlap)
    //{
    //     Show message to user
    //    pManager->GetOutput()->PrintMsg("Cannot place component here (overlap)");

    //    return; // Stop execution
    //}

 

    // Create the connection
    Connection* pConn = new Connection(gfxConn, srcPin, dstPin);
    pConn->setSourcePin(srcPin);
    pConn->setDestPin(dstPin);

    // Add to manager and update GUI
    pManager->AddComponent(pConn);
    pManager->UpdateInterface();
}
void AddConnection::Undo()
{
}

void AddConnection::Redo()
{
}