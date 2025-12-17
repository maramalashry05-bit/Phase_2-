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
        // Be defensive: destination component or pin may be missing — fall back to preserving existing endpoint
        GraphicsInfo gfx;
        GraphicsInfo dstGfx;
        bool haveDstGfx = false;

        if (conn->getDestPin() && conn->getDestPin()->getComponent())
        {
            dstGfx = conn->getDestPin()->getComponent()->GetGraphicsInfo();
            haveDstGfx = true;
        }

        GraphicsInfo srcCompGfx = newSrc->GetGraphicsInfo();
        gfx.x1 = srcCompGfx.x2;
        gfx.y1 = (srcCompGfx.y1 + srcCompGfx.y2) / 2;

        if (haveDstGfx)
        {
            gfx.x2 = dstGfx.x1;
            gfx.y2 = (dstGfx.y1 + dstGfx.y2) / 2;
        }
        else
        {
            // preserve previous end point if dest component info is missing
            GraphicsInfo old = conn->GetGraphicsInfo();
            gfx.x2 = old.x2;
            gfx.y2 = old.y2;
        }

        conn->SetGraphicsInfo(gfx);
        pManager->UpdateInterface();
        pOut->PrintMsg("Connection source updated.");
    }
    else
    {
        // Change destination: user clicks the new destination gate then automatically assign any open input pin
        pOut->PrintMsg("Click on the gate to be the new DESTINATION (will auto-assign an open input pin) or ESC to cancel.");
        pIn->GetPointClicked(x, y);
        pOut->ClearStatusBar();

        Component* newDst = pManager->GetComponentAt(x, y);
        if (!newDst)
        {
            pOut->PrintMsg("No gate selected. Edit cancelled.");
            return;
        }

        // Find first available (not connected) input pin. Components use 1-based indexing for pins.
        InputPin* availablePin = nullptr;
        for (int pinIndex = 1; ; ++pinIndex)
        {
            InputPin* pin = newDst->GetInputPin(pinIndex);
            if (!pin)
                break; // no more pins
            if (!pin->isConnected())
            {
                availablePin = pin;
                break;
            }
        }

        if (!availablePin)
        {
            pOut->PrintMsg("No available input pins on selected gate. Edit cancelled.");
            return;
        }

        conn->setDestPin(availablePin);

        // Update graphics for connection endpoints
        // Be defensive: source component/pin may be missing — fall back to preserving previous start point
        GraphicsInfo gfx;
        GraphicsInfo dstGfx = newDst->GetGraphicsInfo();

        if (conn->getSourcePin() && conn->getSourcePin()->getComponent())
        {
            GraphicsInfo srcGfx = conn->getSourcePin()->getComponent()->GetGraphicsInfo();
            gfx.x1 = srcGfx.x2;
            gfx.y1 = (srcGfx.y1 + srcGfx.y2) / 2;
        }
        else
        {
            // preserve previous start point if source component info is missing
            GraphicsInfo old = conn->GetGraphicsInfo();
            gfx.x1 = old.x1;
            gfx.y1 = old.y1;
        }

        gfx.x2 = dstGfx.x1;
        gfx.y2 = (dstGfx.y1 + dstGfx.y2) / 2;

        conn->SetGraphicsInfo(gfx);
        pManager->UpdateInterface();
        pOut->PrintMsg("Connection destination updated (auto-assigned input pin).");
    }
}