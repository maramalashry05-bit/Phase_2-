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
# include "AddSwitch.h"
#include "SelectAction.h"
#include "AddConnection.h"
#include "Delete.h"
#include "Copy.h"
# include "Cut.h"
#include "Paste.h"
#include "Move.h"
#include "AddLabel.h"
#include "EditLabel.h"
#include "EditConnection.h"
#include "Actions\Probing.h"
#include "Actions\DesignMode.h"
// #include "Exit.h" // Commented out because "Exit.h" does not exist or is not needed
#include "Components/Connection.h"
#include "Actions/Save.h"     
#include "Actions/Load.h"      
#include <fstream>
#include "Actions/Validation.h"
#include "Switch.h"
#include "Actions/Simulation.h"


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

void ApplicationManager::Exit()
{
	delete [] CompList;
	delete OutputInterface;
	delete InputInterface;
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
		case ADD_Switch:
			pAct = new AddSwitch(this);
			break;

		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			break;
	
		case SELECT:
		{
			pAct = new SelectAction(this);
			pAct->Execute();

			// We must delete the action here because we are inside the case
			delete pAct;
			pAct = NULL;

			// If the user is in Simulation Mode, we check if they clicked a switch
			if (UI.AppMode == SIMULATION)
			{
				// Get the component that was just selected/clicked
				Component* pComp = GetSelectedComponent();

				// Try to cast it to a Switch
				Switch* pSw = dynamic_cast<Switch*>(pComp);

				if (pSw)
				{
					pSw->Toggle();         // Flip the Switch (ON/OFF)
					SimulateCircuit();     // Run the "Engine" to propagate the signal
					UpdateInterface();     // Redraw so the LED changes color
				}
			}
		}
			break;

		case DEL:
			pAct = new Delete (this);
			break;

		case COPY:
			pAct = new Copy(this);
			break;
		case CUT:
			pAct = new Cut(this);
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
		
		case EDIT_Connection:
			pAct = new EditConnection(this);
			break;

		case PROBE: 
			pAct = new Probing(this);
			break;
		case DESIGN_MODE:
			pAct = new DesignMode(this);
			break;

		case SAVE: 
			pAct = new Save(this);
			break;

		case LOAD: 
			pAct = new Load(this);
			break;

		case Check_Validation: 
			pAct = new Validation(this);
			break;

		case EXIT:
			///TODO: create ExitAction here
			break;

		case Change_Switch:
		{	// This handles the user clicking the specific tool in the toolbar
			// We reuse the SimulateCircuit logic
			int x, y;
			InputInterface->GetPointClicked(x, y);
			Component* pComp = GetComponent(x, y);
			Switch* pSw = dynamic_cast<Switch*>(pComp);
			if (pSw) {
				pSw->Toggle();
				SimulateCircuit();
				UpdateInterface();
			}
		}
			break;

		case SIM_MODE: // The action that switches from Design to Simulation
		{
			pAct = new Simulation(this); // You'll create this class
		}
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

Component* ApplicationManager::GetOverlap(int x1, int y1, int x2, int y2)
{
	for (int i = 0; i < CompCount; i++)
	{
		Component* comp = CompList[i];
		GraphicsInfo g = comp->GetGraphicsInfo();

		// Check overlap
		if (!(x2 < g.x1 || x1 > g.x2 || y2 < g.y1 || y1 > g.y2))
			return comp;  // Return the overlapped component
	}
	return nullptr; // No overlap
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
	if (SelectedCount > 0)
		return SelectedComponent[0];
	return nullptr;
}


void ApplicationManager::SaveAll(std::ofstream& OutFile) const
{
    // Write Component Count (Only Gates/LEDs/Switches)
    int NonConnCompCount = 0;
    for (int i = 0; i < CompCount; i++)
    {
        if (CompList[i] && !dynamic_cast<Connection*>(CompList[i]))
            NonConnCompCount++;
    }
    OutFile << NonConnCompCount << std::endl;

    // Write Component Data (Gates/LEDs/Switches)
    int CurrentID = 1;
    for (int i = 0; i < CompCount; i++)
    {
        if (CompList[i] && !dynamic_cast<Connection*>(CompList[i]))
        {
            // This calls the specific Save() function for each gate/LED/Switch
            CompList[i]->save(OutFile, CurrentID++); 
        }
    }
    OutFile << "Connections" << std::endl; //seperator

    // Write Connections
    for (int i = 0; i < CompCount; i++)
    {
        if (Connection* conn = dynamic_cast<Connection*>(CompList[i]))
        {
            conn->save(OutFile, 0); 
        }
    }
    OutFile << -1 << std::endl; //terminator
}
void ApplicationManager::LoadAll(std::ifstream& InFile)
{
	

	// Load Components (Gates/LEDs/Switches)
	int CompCountFromFile;
	InFile >> CompCountFromFile;

	std::string CompType;
	for (int i = 0; i < CompCountFromFile; i++)
	{
		InFile >> CompType;
		Component* pComp = nullptr;
		GraphicsInfo GfxInfo; 

		
		if (CompType == "AND2") pComp = new AND2(GfxInfo, 1);
		else if (CompType == "OR2") pComp = new OR2(GfxInfo,1);
		else if (CompType == "LED") pComp = new LED(GfxInfo,1);


		if (pComp)
		{
			pComp->load(InFile);
			AddComponent(pComp);
		}
	}

	// Load Connections
	InFile >> CompType; // Reads "Connections"

	int SrcID, DstID, PinNum;
	while (InFile >> SrcID && SrcID != -1)
	{
		InFile >> DstID >> PinNum;

		Component* pSrcComp = FindComponentByID(SrcID);
		Component* pDstComp = FindComponentByID(DstID);

		if (pSrcComp && pDstComp)
		{
			OutputPin* pSrcPin = pSrcComp->GetOutputPin();
			InputPin* pDstPin = pDstComp->GetInputPin(PinNum);

			GraphicsInfo GfxInfo;
			Connection* pConn = new Connection(GfxInfo, pSrcPin, pDstPin);

			pDstPin->setConnection(pConn);
			pSrcPin->ConnectTo(pConn);

			AddComponent(pConn);
		}
	}
}

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


bool ApplicationManager::ValidateCircuit() 
{
	// Iterate through all components
	for (int i = 0; i < CompCount; i++)
	{
		Component* pComp = CompList[i];

		if (!pComp || dynamic_cast<Connection*>(pComp))
			continue; // Skip null components and connections

		// Check Output Pins
		OutputPin* pOutPin = pComp->GetOutputPin();

		// Check if the component has an output pin (Gates and Switches have one)
		if (pOutPin)
		{
			// If the output pin exists but has zero connections, it's a floating output.
			// LEDs do NOT have output pins, so they are skipped by this check.
			if (pOutPin->getConnCount() == 0)
			{
				GetOutput()->PrintMsg("Validation FAILED: Output pin of component " + pComp->GetLabel() + " is unconnected.");
				return false;
			}
		}

		// Iterate through input pin indices 1, 2, 3...
		// We'll iterate up to a high limit (e.g., 5) to safely cover all gate types.
		for (int n = 1; n <= 5; n++)
		{
			InputPin* pInPin = pComp->GetInputPin(n);

			// Check if the component has an input pin at this index
			if (pInPin)
			{
				// If the pin exists but has no connection, the circuit is invalid (floating input).
				
				if (!pInPin->getConnection())
				{
					GetOutput()->PrintMsg("Validation FAILED: Input pin " + std::to_string(n) + " of component " + pComp->GetLabel() + " is unconnected.");
					return false;
				}
			}
		}
	}

	// If the loop completes without finding any floating pins, the circuit is valid.
	GetOutput()->PrintMsg("Circuit Validation SUCCESS! Ready for Simulation.");
	return true;
}

void ApplicationManager::SimulateCircuit()
{
	// We loop multiple times to allow signals to propagate 
	// from Switches through Gates to LEDs.
	// Why loop 5 times? 
	//  1: Switch sets its Pin.
	//  2: Connection reads Switch Pin and sets Gate/LED Pin.
	//  3: Gate reads its Input Pins and sets its Output Pin.
	//  4: Next Connection carries Gate output to LED.
	//  5: LED reads its Input Pin and turns ON.
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < CompCount; j++)
		{
			if (CompList[j])
			{
				// Polymorphically call Operate for each component.
				CompList[j]->Operate();
			}
		}
	}
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

