#include "Copy.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"

Copy::Copy(ApplicationManager* pApp) : Action(pApp) {}

void Copy::Execute()
{
    Output* pOut = pManager->GetOutput();

    Component* sel = pManager->GetSelectedComponent();
    if (!sel) {
        pOut->PrintMsg("No component selected to copy.");
        return;
    }

    // Store a copy in clipboard
    pManager->SetClipboard(sel->Clone());

    pOut->PrintMsg("Component copied.");
}
