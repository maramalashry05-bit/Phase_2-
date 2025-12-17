#include "SwitchToSimulation.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"

SwitchToSimulation::SwitchToSimulation(ApplicationManager* pApp)
    : Action(pApp)
{
}

void SwitchToSimulation::ReadActionParameters()
{
    // No parameters needed
}

void SwitchToSimulation::Execute()
{
    // STEP 1: validate circuit
    if (!pManager->ValidateCircuit())
        return;

    // STEP 2: switch mode
    pManager->SetAppMode(SIMULATION);

    // STEP 3: draw simulation toolbar
    pManager->GetOutput()->CreateSimulationToolBar();

    // STEP 4: clear status bar
    pManager->GetOutput()->ClearStatusBar();
}

void SwitchToSimulation::Undo()
{
}

void SwitchToSimulation::Redo()
{
}
