#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Component* SelectedComponent = nullptr;
	Component* Clipboard = nullptr;  // stores the copied component


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
	bool isOverlab(int x1, int y1, int x2, int y2);
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	void unselectAll();
	Component* GetComponentAt(int x, int y);
	//destructor
	~ApplicationManager();

	Component* GetSelectedComponent() const;
	void SetSelectedComponent(Component* comp);
	void RemoveComponent(Component* comp);
	void SetClipboard(Component* comp);
	Component* GetClipboard() const;

};

#endif