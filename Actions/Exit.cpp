#include "Exit.h"

Exit::Exit(ApplicationManager* pApp) : Action(pApp)
{
}

Exit :: ~Exit(void) {}

void Exit::ReadActionParameters()
{
	//No parameters to read from user
}

void Exit::Execute()
{
	//Call the ApplicationManager's Exit function
	pManager->Exit();
}
