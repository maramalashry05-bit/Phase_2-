#include "Paste.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"
#include "GUI/Input.h"

Paste::Paste(ApplicationManager* pApp) : Action(pApp) {}

void Paste::Execute()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    // Get the component from the clipboard
    Component* clip = pManager->GetClipboard();
    if (!clip) {
        pOut->PrintMsg("Clipboard is empty. Copy a component first.");
        return;
    }

    // Clone the component
    Component* newComp = clip->Clone();

    // Ask the user where to paste it
    pOut->PrintMsg("Click to place the pasted component.");
    int x, y;
    pIn->GetPointClicked(x, y); // Wait for user click

    // Update the component's position
    GraphicsInfo g = newComp->GetGraphicsInfo();
    int width = g.x2 - g.x1;
    int height = g.y2 - g.y1;

    g.x1 = x;
    g.y1 = y;
    g.x2 = x + width;
    g.y2 = y + height;

    newComp->SetGraphicsInfo(g);

    // Add the new component to the application
    pManager->AddComponent(newComp);
    pManager->UpdateInterface();

    pOut->PrintMsg("Component pasted.");
}
