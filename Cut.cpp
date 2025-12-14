#include "Cut.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"

Cut::Cut(ApplicationManager* pApp) : Action(pApp) {}

void Cut::Execute()
{
    Output* pOut = pManager->GetOutput();

    // 1? Get the selected component
    Component* sel = pManager->GetSelectedComponent();
    if (!sel) {
        pOut->PrintMsg("No component selected to cut.");
        return;
    }

    // 2? Copy the component to the clipboard
    pManager->SetClipboard(sel->Clone());

    // 3? Remove the component along with all attached connections
    pManager->RemoveComponent(sel);

    // 4? Update GUI
    pManager->UpdateInterface();

    pOut->PrintMsg("Component cut successfully.");
}
