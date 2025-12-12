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

    Component* sel = pManager->GetSelectedComponent();
    if (!sel) {
        pOut->PrintMsg("No component selected to move.");
        return;
    }

    pOut->PrintMsg("Click on canvas to move the selected component.");
    int x, y;
    pIn->GetPointClicked(x, y);

    GraphicsInfo g = sel->GetGraphicsInfo();
    int width = g.x2 - g.x1;
    int height = g.y2 - g.y1;

    // Optional: Keep inside drawing area
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x + width > UI.width) x = UI.width - width;
    if (y + height > UI.height - UI.StatusBarHeight) y = UI.height - UI.StatusBarHeight - height;

    g.x1 = x;
    g.y1 = y;
    g.x2 = x + width;
    g.y2 = y + height;

    sel->SetGraphicsInfo(g);

    pManager->UpdateInterface();
    pOut->PrintMsg("Component moved.");
}