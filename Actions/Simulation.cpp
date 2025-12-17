#include "Simulation.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

Simulation::Simulation(ApplicationManager* pApp) : Action(pApp)
{
}

void Simulation::ReadActionParameters()
{
    // Get a pointer to the Output interface to display messages
    Output* pOut = pManager->GetOutput();
    pOut->PrintMsg("Entering Simulation Mode. Click on switches to toggle them.");
}

void Simulation::Execute()
{
    // 1. Get user parameters (the message)
    ReadActionParameters();

    // 2. Change the Global UI mode to Simulation
    // This tells the Input class to use the Simulation toolbar mapping
    UI.AppMode = SIMULATION;

    // 3. Create the Simulation Toolbar
    pManager->GetOutput()->CreateSimulationToolBar();

    // 4. Perform initial circuit validation (Optional but recommended)
    // If the circuit is invalid (floating pins), you might want to alert the user
    if (!pManager->ValidateCircuit()) {
        pManager->GetOutput()->PrintMsg("Warning: Circuit has unconnected pins!");
    }

    // 5. Run the first propagation logic
    // This ensures LEDs reflect the current switch positions immediately
    pManager->SimulateCircuit();
}