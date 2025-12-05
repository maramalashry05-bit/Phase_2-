//#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pOut)
{
	string userInput = "";   // To store the typed string
	char key;

	while (true)
	{
		pWind->WaitKeyPress(key);// Wait for a key press

		if (key == 27)  // ESCAPE key
		{
			userInput = "";  // Return empty string
			break;
		}
		else if (key == 13) // ENTER key
		{
			break;  // Finished typing
		}
		else if (key == 8) // BACKSPACE key
		{
			if (!userInput.empty())
			{
				userInput.pop_back();           // Remove last character
				pOut->PrintMsg(userInput);     // Update status bar
			}
		}
		else
		{
			userInput += key;                   // Append character
			pOut->PrintMsg(userInput);          // Update status bar
		}
	}

	return userInput;  // Return the typed string
}




//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				// GATES AND,NAND

			case ITM_AND2:     return ADD_AND_GATE_2;
			case ITM_AND3:     return ADD_AND_GATE_3;
			case ITM_NAND2:    return ADD_NAND_GATE_2;
			case ITM_NAND3:    return ADD_NAND_GATE_3;

				//GATES OR,NOR

			case ITM_OR2:      return ADD_OR_GATE_2;
			case ITM_OR3:      return ADD_OR_GATE_3;
			case ITM_NOR2:     return ADD_NOR_GATE_2;
			case ITM_NOR3:     return ADD_NOR_GATE_3;

				//GATES XOR,XNOR

			case ITM_XOR2:     return ADD_XOR_GATE_2;
			case ITM_XOR3:     return ADD_XOR_GATE_3;
			case ITM_XNOR2:    return ADD_XNOR_GATE_2;
			case ITM_XNOR3:    return ADD_XNOR_GATE_3;

				//BUFF , INV

			case ITM_BUFF:		return ADD_BUFF;
			case ITM_INV:		return ADD_INV;
			
				// BASIC COMPONENTS
			case ITM_SWITCH:        return ADD_Switch;
			case ITM_LED:           return ADD_LED;
			case ITM_CONNECTION:    return ADD_CONNECTION;

				// LABEL HANDLING 
			case ITM_ADD_LABEL:     return ADD_Label;
			case ITM_EDIT_LABEL:    return EDIT_Label;

				// EDITING 
			case ITM_COPY:          return COPY;
			case ITM_CUT:           return CUT;
			case ITM_PASTE:         return PASTE;

			case ITM_SELECT:        return SELECT;
			case ITM_MOVE:          return MOVE;
			case ITM_DEL:           return DEL;

				// FILE
			case ITM_SAVE:          return SAVE;
			case ITM_LOAD:          return LOAD;

				// UNDO/REDO 
			case ITM_UNDO:          return UNDO;
			case ITM_REDO:          return REDO;

				// MODE SWITCH
			case ITM_SIM_MODE:      return SIM_MODE;

				// EXIT 
			case ITM_EXIT:          return EXIT;

			default:                return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = x / UI.ToolItemWidth;

			switch (ClickedItemOrder)
			{
			case ITM_SIM:               return Start_Simulation;
			case ITM_TRUTH:             return Create_TruthTable;
			case ITM_SWITCH_CHANGE:     return Change_Switch;
			case ITM_CHECK_VALIDATION:  return Check_Validation;
			case ITM_INSPECT_VALUE:     return Inspect_Value;
			case ITM_DSN_MODE:          return DSN_MODE;

			default:                    return SIM_TOOL;
			}
		}

		//[2] User clicks on the simulation area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			return SELECT;

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
}

Input::~Input()

{
}
