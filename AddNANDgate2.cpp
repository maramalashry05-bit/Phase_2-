#include "AddNANDgate2.h"
#include "ApplicationManager.h"

AddNANDgate2::AddNANDgate2(ApplicationManager* pApp)
	: Action(pApp), Cx(0), Cy(0), x1(0), y1(0), x2(0), y2(0)
{
}

AddNANDgate2::~AddNANDgate2(void)
{
}

void AddNANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input NAND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNANDgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.NAND2_Width;
	int Wdth = UI.NAND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the NAND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	Component* overlap = pManager->GetOverlap(GInfo.x1, GInfo.y1, GInfo.x2, GInfo.y2);
	if (overlap)
	{
		// Show message to user
		pManager->GetOutput()->PrintMsg("Cannot place component here (overlap)");
		return; // Stop execution
	}

	
	NAND2* pA = new NAND2(GInfo, NAND2_FANOUT);
	pManager->AddComponent(pA);
	pManager->UpdateInterface();
}

void AddNANDgate2::Undo()
{
}

void AddNANDgate2::Redo()
{
}