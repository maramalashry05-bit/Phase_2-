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
#include "AddXNORgate3.h"
#include "AddXNORgate2.h"
#include "AddBUFFgate.h"
#include "AddINVgate.h"
#include "AddLED.h"
#include "SelectAction.h"
#include "AddConnection.h"
#include "Delete.h"
#include "Copy.h"
#include "Paste.h"
#include "Move.h"
#include "AddLabel.h"
#include "EditLabel.h"
#include "Actions\Probing.h"
#include "Components/Connection.h"
//#include "Save.h"     
//#include "Load.h"      
//#include <fstream>


ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	SelectedCount = 0;

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

	void ApplicationManager::unselectAll()
	{
		for (int i = 0; i < SelectedCount; i++)
		{
			if (SelectedComponent[i] != nullptr)
				SelectedComponent[i]->Setselected(false);
		}

		SelectedCount = 0;
	}



Component* ApplicationManager::GetComponentAt(int x, int y) {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->IsInside(x, y))
			return CompList[i];
	}
	return NULL;
}

void ApplicationManager::SetClipboard(Component* comp)
{
	if (Clipboard) delete Clipboard;  // delete previous clipboard content
	Clipboard = comp;
}

Component* ApplicationManager::GetClipboard() const
{
	return Clipboard;
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
		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;
		case ADD_XNOR_GATE_3:
			pAct = new AddXNORgate3(this);
			break;
		case ADD_BUFF:
			pAct = new AddBUFFgate(this);
			break;
		case ADD_INV:
			pAct = new AddINVgate(this);
			break;
		case ADD_LED:
			pAct = new AddLED(this);
			break;

		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			break;
	
		case SELECT:
			pAct = new SelectAction(this);
			break;

		case DEL:
			pAct = new Delete (this);
			break;

		case COPY:
			pAct = new Copy(this);
			break;

		case PASTE:
			pAct = new Paste(this);
			break;

		case MOVE:
			pAct = new Move(this);
			break;
		
		case ADD_Label:
			pAct = new AddLabel(this);
			break;
		
		case EDIT_Label:
			pAct = new EditLabel(this);
			break;
		case PROBE: // Assuming PROBE is an enumeration value in Defs.h
			pAct = new Probing(this);
			break;

		/*case SAVE: 
			pAct = new Save(this);
			break;

		case LOAD: 
			pAct = new Load(this);
			break;*/

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
	// Clear drawing area first so removed components don't remain visible
	OutputInterface->ClearDrawingArea();

	// Redraw all remaining components
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

Component* ApplicationManager::GetComponent(int x, int y)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->IsInside(x, y))
		{
			return CompList[i];
		}
	}
	return nullptr; // No component found at the given coordinates
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
Component* ApplicationManager::GetSelectedComponent() const
{
	for(int i =0;i< CompCount;i++)
	return SelectedComponent[i];
}

//void ApplicationManager::SaveAll(std::ofstream& OutFile) const
//{
//    // Write Component Count (Only Gates/LEDs/Switches)
//    int NonConnCompCount = 0;
//    for (int i = 0; i < CompCount; i++)
//    {
//        if (CompList[i] && !dynamic_cast<Connection*>(CompList[i]))
//            NonConnCompCount++;
//    }
//    OutFile << NonConnCompCount << std::endl;
//
//    // Write Component Data (Gates/LEDs/Switches)
//    int CurrentID = 1;
//    for (int i = 0; i < CompCount; i++)
//    {
//        if (CompList[i] && !dynamic_cast<Connection*>(CompList[i]))
//        {
//            // This calls the specific Save() function for each gate/LED/Switch
//            CompList[i]->Save(OutFile, CurrentID++); 
//        }
//    }
//    OutFile << "Connections" << std::endl; //seperator
//
//    // Write Connections
//    for (int i = 0; i < CompCount; i++)
//    {
//        if (Connection* conn = dynamic_cast<Connection*>(CompList[i]))
//        {
//            conn->Save(OutFile, 0); 
//        }
//    }
//    OutFile << -1 << std::endl; //terminator
//}
//void ApplicationManager::LoadAll(std::ifstream& InFile)
//{
//	
//
//	// Load Components (Gates/LEDs/Switches)
//	int CompCountFromFile;
//	InFile >> CompCountFromFile;
//
//	std::string CompType;
//	for (int i = 0; i < CompCountFromFile; i++)
//	{
//		InFile >> CompType;
//		Component* pComp = nullptr;
//		GraphicsInfo GfxInfo; 
//
//		
//		if (CompType == "AND2") pComp = new AND2(GfxInfo);
//		else if (CompType == "OR2") pComp = new OR2(GfxInfo);
//		else if (CompType == "LED") pComp = new LED(GfxInfo);
//
//		if (pComp)
//		{
//			pComp->Load(InFile);
//			AddComponent(pComp);
//		}
//	}
//
//	// Load Connections
//	InFile >> CompType; // Reads "Connections"
//
//	int SrcID, DstID, PinNum;
//	while (InFile >> SrcID && SrcID != -1)
//	{
//		InFile >> DstID >> PinNum;
//
//		Component* pSrcComp = FindComponentByID(SrcID);
//		Component* pDstComp = FindComponentByID(DstID);
//
//		if (pSrcComp && pDstComp)
//		{
//			OutputPin* pSrcPin = pSrcComp->GetOutputPin();
//			InputPin* pDstPin = pDstComp->GetInputPin(PinNum);
//
//			GraphicsInfo GfxInfo;
//			Connection* pConn = new Connection(GfxInfo, pSrcPin, pDstPin);
//
//			pDstPin->setConnection(pConn);
//			pSrcPin->ConnectTo(pConn);
//
//			AddComponent(pConn);
//		}
//	}
//}

void ApplicationManager::ClearCircuit()
{
	// Delete all existing components
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];

	// Reset counts and pointers
	CompCount = 0;
	SelectedCount = 0;
	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = nullptr;

	if (Clipboard)
	{
		delete Clipboard;
		Clipboard = nullptr;
	}

	// Reset the unique ID counter 

	GetOutput()->ClearDrawingArea();
}


Component* ApplicationManager::FindComponentByID(int ID) const
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] && CompList[i]->GetID() == ID)
			return CompList[i];
	}
	return nullptr;
}


void ApplicationManager::SetSelectedComponent(Component* comp)
{
	if (comp == nullptr) return;

	// prevent duplicate selection
	for (int i = 0; i < SelectedCount; i++)
		if (SelectedComponent[i] == comp)
			return;

	comp->Setselected(true);
	SelectedComponent[SelectedCount++] = comp;
}

void ApplicationManager::UnselectComponent(Component* comp)
{
	if (!comp) return;

	for (int i = 0; i < SelectedCount; i++)
	{
		if (SelectedComponent[i] == comp)
		{
			comp->Setselected(false);

			// shift left
			for (int j = i; j < SelectedCount - 1; j++)
				SelectedComponent[j] = SelectedComponent[j + 1];

			SelectedCount--;
			return;
		}
	}
}


void ApplicationManager::RemoveComponent(Component* C)
{
	if (!C) return;

	// 1. Delete ALL connections attached to this component
	for (int i = 0; i < CompCount; i++)
	{
		Connection* conn = dynamic_cast<Connection*>(CompList[i]);
		if (!conn) continue;

		Component* srcOwner = conn->getSourcePin() ? conn->getSourcePin()->getComponent() : nullptr;
		Component* dstOwner = conn->getDestPin() ? conn->getDestPin()->getComponent() : nullptr;

		if (srcOwner == C || dstOwner == C)
		{
			// --- CLEAN OUTPUT PIN ---
			OutputPin* out = conn->getSourcePin();
			if (out)
				out->RemoveConnection(conn);

			// --- CLEAN INPUT PIN ---
			InputPin* in = conn->getDestPin();
			if (in)
				in->RemoveConnection();   // <--- THIS MAKES THE PIN FREE AGAIN

			// NOW it is safe to delete the connection
			delete conn;

			// Shift component list
			for (int j = i; j < CompCount - 1; j++)
				CompList[j] = CompList[j + 1];

			CompList[CompCount - 1] = nullptr;
			CompCount--;
			i--; // stay at same index
		}
	}

	// 2. Remove the component itself
	int idx = -1;
	for (int i = 0; i < CompCount; i++)
		if (CompList[i] == C) { idx = i; break; }

	if (idx != -1)
	{
		delete C;

		for (int j = idx; j < CompCount - 1; j++)
			CompList[j] = CompList[j + 1];

		CompList[CompCount - 1] = nullptr;
		CompCount--;
	}

}
