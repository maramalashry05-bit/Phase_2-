#include "AddNORgate3.h"
#include "ApplicationManager.h"

AddNORgate3::AddNORgate3(ApplicationManager* pApp)
	: Action(pApp), Cx(0), Cy(0), x1(0), y1(0), x2(0), y2(0)
{
}

AddNORgate3::~AddNORgate3(void)
{
}

void AddNORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input NOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNORgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.NOR3_Width;
	int Wdth = UI.NOR3_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the NOR2 gate

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

	
	NOR3* pA = new NOR3(GInfo, NOR3_FANOUT);
	pManager->AddComponent(pA);
	pManager->UpdateInterface();
}

void AddNORgate3::Undo()
{
}

void AddNORgate3::Redo()
{
}