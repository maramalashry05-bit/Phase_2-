#include "Delete.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"

Delete::Delete(ApplicationManager* pApp) : Action(pApp) {}

void Delete::Execute()
{
    Output* pOut = pManager->GetOutput();

    int count = pManager->GetSelectedCount();
    if (count == 0)
    {
        pOut->PrintMsg("No components selected to delete.");
        return;
    }

    // Delete from last to first to avoid index issues
    for (int i = count - 1; i >= 0; i--)
    {
        // Use a public accessor to get the selected component
        Component* C = pManager->GetSelectedComponent(i);
        if (C != nullptr)
            pManager->RemoveComponent(C);
    }

    pManager->unselectAll();
    pManager->UpdateInterface();
    pOut->PrintMsg("Selected components deleted.");
}


Component* ApplicationManager::GetSelectedComponent(int index) const
{
    if (index >= 0 && index < SelectedCount)
        return SelectedComponent[index];
    return nullptr;
}
