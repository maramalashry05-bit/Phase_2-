#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "AddANDgate3.h"
#include "AddNANDgate2.h"
#include "AddNANDgate3.h"
#include "SelectAction.h"


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

		case ADD_CONNECTION:
			//TODO: Create AddConection Action here
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
	for (int i; i < CompCount; i++)
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

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}