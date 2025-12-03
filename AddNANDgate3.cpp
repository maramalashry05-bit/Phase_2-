#include "AddNANDgate3.h"
#include "ApplicationManager.h"

AddNANDgate3::AddNANDgate3(ApplicationManager* pApp) :Action(pApp), Cx(0), Cy(0), x1(0), y1(0), x2(0), y2(0)
{
}

AddNANDgate3::~AddNANDgate3(void)
{
}

void AddNANDgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input NAND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNANDgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.NAND3_Width;
	int Wdth = UI.NAND3_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the NAND3 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	NAND3* pA = new NAND3(GInfo, NAND3_FANOUT);
	pManager->AddComponent(pA);
}

void AddNANDgate3::Undo()
{
}

void AddNANDgate3::Redo()
{
}