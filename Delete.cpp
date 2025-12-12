#include "Delete.h"
#include "ApplicationManager.h"
#include "Actions\Action.h"

Delete::Delete(ApplicationManager* pApp) : Action(pApp) {}

void Delete::Execute()
{
    Output* pOut = pManager->GetOutput();
    Component* sel = pManager->GetSelectedComponent();
    if (!sel) { pOut->PrintMsg("No component selected to delete."); return; }
    pManager->RemoveComponent(sel);
    pManager->SetSelectedComponent(nullptr);
    pManager->UpdateInterface();
    pOut->PrintMsg("Deleted.");
}
