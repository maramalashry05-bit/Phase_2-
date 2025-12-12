#include "Paste.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"

Paste::Paste(ApplicationManager* pApp) : Action(pApp) {}

void Paste::Execute()
{
    Output* pOut = pManager->GetOutput();

    Component* clip = pManager->GetClipboard();
    if (!clip) {
        pOut->PrintMsg("Clipboard is empty. Copy a component first.");
        return;
    }

    // Clone the component again for a new instance
    Component* newComp = clip->Clone();

    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Click to place the pasted component.");
    int x, y;
    pIn->GetPointClicked(x, y);  // waits for user to click

    GraphicsInfo g = newComp->GetGraphicsInfo();
    int width = g.x2 - g.x1;
    int height = g.y2 - g.y1;

    // Move component to clicked position
    g.x1 = x;
    g.y1 = y;
    g.x2 = x + width;
    g.y2 = y + height;

    newComp->SetGraphicsInfo(g);


    // Add to ApplicationManager
    pManager->AddComponent(newComp);
    pManager->UpdateInterface();

    pOut->PrintMsg("Component pasted.");
}
