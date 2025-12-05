#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "AddANDgate3.h"
#include "AddORgate2.h"	
#include "AddORgate3.h"
#include "AddNORgate2.h"
#include "AddNORgate3.h"
#include "AddXORgate2.h"
#include "AddXORgate3.h"
#include "AddNANDgate2.h"
#include "AddNANDgate3.h"
#include "SelectAction.h"
#include "AddConnection.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::unselectAll() {
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->Setselected(false);
	}
}

Component* ApplicationManager::GetComponentAt(int x, int y) {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->IsInside(x, y))
			return CompList[i];
	}
	return NULL;
}


ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);	
			break;
		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;
		case ADD_NAND_GATE_3:
			pAct = new AddNANDgate3(this);
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;
		case ADD_OR_GATE_3:
			pAct = new AddORgate3(this);
			break;
		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;
		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;
		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;
		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			break;

		case ADD_CONNECTION:
			//TODO: Create AddConection Action here
			pAct = new AddConnection(this);
			break;
	
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}
Component* ApplicationManager::Getcomponent(int index)
{
	for (int i=0; i < CompCount; i++)
	{
		if (i == index)
		{
			return(CompList[i]);
		}
	}
}
int ApplicationManager::GetComponentCount()
{
	return CompCount;
}

bool ApplicationManager::isOverlab(int x1, int y1, int x2, int y2)
{
	// Loop through all components
	for (int i = 0; i < CompCount; i++)  // CompCount = number of components
	{
		Component* comp = CompList[i];  // your array/list of components
		GraphicsInfo g = comp->GetGraphicsInfo();

		// Check overlap
		if (!(x2 < g.x1 || x1 > g.x2 || y2 < g.y1 || y1 > g.y2))
			return false; // Overlap detected
	}
	return true; // No overlap
}


////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}