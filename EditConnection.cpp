#include "EditConnection.h"
#include "Components/Connection.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Components/Component.h"

void EditConnection::Execute()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    Component* sel = pManager->GetSelectedComponent();
    if (!sel)
    {
        pOut->PrintMsg("No component selected.");
        return;
    }

    // Ensure selected component is a Connection
    Connection* conn = dynamic_cast<Connection*>(sel);
    if (!conn)
    {
        pOut->PrintMsg("Selected component is not a connection.");
        return;
    }

    pOut->PrintMsg("Edit Connection: Enter 1 to change SOURCE, 2 to change DESTINATION (ESC to cancel):");
    std::string choiceStr = pIn->GetSrting(pOut);
    pOut->ClearStatusBar();
    if (choiceStr.empty())
    {
        pOut->PrintMsg("Edit cancelled.");
        return;
    }

    int choice = 0;
    try { choice = std::stoi(choiceStr); }
    catch (...)
    {
        pOut->PrintMsg("Invalid choice. Edit cancelled.");
        return;
    }

    if (choice != 1 && choice != 2)
    {
        pOut->PrintMsg("Choice must be 1 or 2. Edit cancelled.");
        return;
    }

    int x, y;
    if (choice == 1)
    {
        // Change source: user clicks the new source gate (must have an output pin)
        pOut->PrintMsg("Click on the gate to be the new SOURCE (must have an output pin) or ESC to cancel.");
        pIn->GetPointClicked(x, y);
        pOut->ClearStatusBar();

        Component* newSrc = pManager->GetComponentAt(x, y);
        if (!newSrc || !newSrc->GetOutputPin())
        {
            pOut->PrintMsg("Invalid source gate. Edit cancelled.");
            return;
        }

        OutputPin* newSrcPin = newSrc->GetOutputPin();
        conn->setSourcePin(newSrcPin);

        // Update graphics for connection endpoints
        GraphicsInfo srcGfx = newSrc->GetGraphicsInfo();
        GraphicsInfo dstGfx = conn->getDestPin()->getComponent()->GetGraphicsInfo();
        GraphicsInfo gfx;
        gfx.x1 = srcGfx.x2;
        gfx.y1 = (srcGfx.y1 + srcGfx.y2) / 2;
        gfx.x2 = dstGfx.x1;
        gfx.y2 = (dstGfx.y1 + dstGfx.y2) / 2;
        conn->SetGraphicsInfo(gfx);
        pManager->UpdateInterface();
        pOut->PrintMsg("Connection source updated.");
    }
    else
    {
        // Change destination: user clicks the new destination gate then enters input pin index
        pOut->PrintMsg("Click on the gate to be the new DESTINATION (must have input pins) or ESC to cancel.");
        pIn->GetPointClicked(x, y);
        pOut->ClearStatusBar();

        Component* newDst = pManager->GetComponentAt(x, y);
        if (!newDst)
        {
            pOut->PrintMsg("No gate selected. Edit cancelled.");
            return;
        }

        // Ask for input pin number (1-based)
        pOut->PrintMsg("Enter input pin number (1..n) for the selected gate or ESC to cancel:");
        std::string pinStr = pIn->GetSrting(pOut);
        pOut->ClearStatusBar();
        if (pinStr.empty())
        {
            pOut->PrintMsg("Edit cancelled.");
            return;
        }

        int pinIndex = 0;
        try { pinIndex = std::stoi(pinStr); }
        catch (...)
        {
            pOut->PrintMsg("Invalid pin number. Edit cancelled.");
            return;
        }

        InputPin* newDstPin = newDst->GetInputPin(pinIndex);
        if (!newDstPin)
        {
            pOut->PrintMsg("Invalid input pin index. Edit cancelled.");
            return;
        }

        conn->setDestPin(newDstPin);

        // Update graphics for connection endpoints
        GraphicsInfo srcGfx = conn->getSourcePin()->getComponent()->GetGraphicsInfo();
        GraphicsInfo dstGfx = newDst->GetGraphicsInfo();
        GraphicsInfo gfx;
        gfx.x1 = srcGfx.x2;
        gfx.y1 = (srcGfx.y1 + srcGfx.y2) / 2;
        gfx.x2 = dstGfx.x1;
        gfx.y2 = (dstGfx.y1 + dstGfx.y2) / 2;
        conn->SetGraphicsInfo(gfx);
        pManager->UpdateInterface();
        pOut->PrintMsg("Connection destination updated.");
    }
}