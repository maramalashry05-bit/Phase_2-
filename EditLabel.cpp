#include "EditLabel.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

void EditLabel::Execute() {
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    Component* sel = pManager->GetSelectedComponent();
    if (!sel) {
        pOut->PrintMsg("No component selected.");
        return;
    }

    // If component has no existing label, inform the user
    const std::string& current = sel->GetLabel();
    if (current.empty()) {
        pOut->PrintMsg("Component has no label to edit.");
        return;
    }

    pOut->PrintMsg("Enter new label text:");
    std::string label = pIn->GetSrting(pOut);
    sel->SetLabel(label);
    pOut->PrintMsg("Label updated: " + label);
}