#include "Move.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
#include "GUI/UI_Info.h"

Move::Move(ApplicationManager* pApp) : Action(pApp) {}

void Move::Execute()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    int count = pManager->GetSelectedCount();
    if (count == 0) {
        pOut->PrintMsg("No components selected to move.");
        return;
    }

    Component** selected = pManager->GetSelectedComponents();

    pOut->PrintMsg("Click on canvas to move the selected components.");
    int newX, newY;
    pIn->GetPointClicked(newX, newY);

    // Compute offset based on first selected component
    Component* first = selected[0];
    GraphicsInfo gFirst = first->GetGraphicsInfo();
    int offsetX = newX - gFirst.x1;
    int offsetY = newY - gFirst.y1;

    for (int i = 0; i < count; i++) {
        Component* comp = selected[i];
        GraphicsInfo g = comp->GetGraphicsInfo();

        g.x1 += offsetX;
        g.y1 += offsetY;
        g.x2 += offsetX;
        g.y2 += offsetY;

        // Keep inside drawing area
        int width = g.x2 - g.x1;
        int height = g.y2 - g.y1;

        if (g.x1 < 0) { g.x1 = 0; g.x2 = width; }
        if (g.y1 < 0) { g.y1 = 0; g.y2 = height; }
        if (g.x2 > UI.width) { g.x2 = UI.width; g.x1 = UI.width - width; }
        if (g.y2 > UI.height - UI.StatusBarHeight) { g.y2 = UI.height - UI.StatusBarHeight; g.y1 = UI.height - UI.StatusBarHeight - height; }

        comp->SetGraphicsInfo(g);
    }

    pManager->UpdateInterface();
    pOut->PrintMsg("Selected components moved.");
}
