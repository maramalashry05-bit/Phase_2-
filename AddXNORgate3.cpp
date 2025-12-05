#include "AddXNORgate3.h"
#include "ApplicationManager.h"

AddXNORgate3::AddXNORgate3(ApplicationManager* pApp)
	: Action(pApp), Cx(0), Cy(0), x1(0), y1(0), x2(0), y2(0)
{
}

AddXNORgate3::~AddXNORgate3(void)
{
}

void AddXNORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input XNOR3 Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXNORgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.XNOR3_Width;
	int Wdth = UI.XNOR3_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the NOR2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	XNOR3* pA = new XNOR3(GInfo, XNOR3_FANOUT);
	pManager->AddComponent(pA);
}

void AddXNORgate3::Undo()
{
}

void AddXNORgate3::Redo()
{
}