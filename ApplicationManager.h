#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include <fstream> 
#include "Actions\Probing.h"
// #include "Exit.h" // Commented out because "Exit.h" does not exist or is not needed
#include "Actions\DesignMode.h"
#include "Actions\Validation.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	int SelectedCount;
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Component* SelectedComponent[MaxCompCount] ;
	Component* Clipboard=nullptr ;  // stores the copied component


public:


public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Component* Getcomponent(int index);
	int GetComponentCount();
	Component* GetComponent(int x, int y);
	Component* GetOverlap(int x1, int y1, int x2, int y2);
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	void unselectAll();
	Component* GetComponentAt(int x, int y);

	void SaveAll(std::ofstream& OutFile) const;
	void LoadAll(std::ifstream& InFile);
	void ClearCircuit();
	Component* FindComponentByID(int ID) const;

	bool ValidateCircuit();
	

	//destructor
	~ApplicationManager();

	Component* GetSelectedComponent() const;
	void SetSelectedComponent(Component* comp);
	void UnselectComponent(Component* comp);
	void RemoveComponent(Component* comp);
	void RemoveComponentConnections(Component* comp);
	void SetClipboard(Component* comp);
	Component* GetClipboard() const;
	void Exit();
};

#endif