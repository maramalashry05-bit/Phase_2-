#include "Probing.h"
#include "..\Components\Connection.h"
#include "..\Components\Gate.h"
#include "..\GUI\UI_Info.h"
#include "..\Defs.h"
#include <string>


Probing::Probing(ApplicationManager* pApp) : Action(pApp)
{
	Cx = 0;
	Cy = 0;
}



void Probing::ReadActionParameters()
{
	//Get pointers to Input and Output
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//display message to user
	pOut->PrintMsg("Probing Mode: Click on any Connection or Gate to check its signal...");

	//Wait for the click
	pIn->GetPointClicked(Cx, Cy);

	//Clear the status bar after the click to prepare for the result
	pOut->ClearStatusBar();
}

void Probing::Execute()
{
	// Read where the user clicked
	ReadActionParameters();

	//Get the Component at these coordinates
	Component* pComp = pManager->GetComponent(Cx, Cy);

	//Check validity and display result
	Output* pOut = pManager->GetOutput();

	if (pComp != NULL)
	{
		// returning the signal (1 or 0)
		int status = pComp->GetOutPinStatus();

		if (status == 1) // High
		{
			pOut->PrintMsg("Signal Status: HIGH (1)");
		}
		else // Low
		{
			pOut->PrintMsg("Signal Status: LOW (0)");
		}
	}
	else
	{
		pOut->PrintMsg("No component found at this location.");
	};
}

void Probing::Undo()
{
	// Probing action is not undoable
}

void Probing::Redo()
{
	// Probing action is not redoable
}