#include "AddLabel.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

void AddLabel::Execute() {
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    Component* sel = pManager->GetSelectedComponent();
    if (!sel) {
        pOut->PrintMsg("No component selected.");
        return;
    }
    pOut->PrintMsg("Enter label text:");
    std::string label = pIn->GetSrting(pOut);
    sel->SetLabel(label);
    pOut->PrintMsg("Label set: " + label);
}