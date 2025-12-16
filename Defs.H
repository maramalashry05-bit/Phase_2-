#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{
	ADD_BUFF,			// Add 1-input Buffer gate
	ADD_INV,			// Add 1-input Inverter gate

	ADD_AND_GATE_2,		// Add 2-input AND gate
	ADD_AND_GATE_3,		// Add 3-input AND gate
	ADD_NAND_GATE_2,	// Add 2-input NAND gate
	ADD_NAND_GATE_3,	// Add 3-input NAND gate

	ADD_OR_GATE_2,		// Add 2-input OR gate
	ADD_OR_GATE_3,		// Add 3-input OR gate
	ADD_NOR_GATE_2,		// Add 2-input NOR gate
	ADD_NOR_GATE_3,		// Add 3-input NOR gate

	ADD_XOR_GATE_2,		// Add 2-input XOR gate
	ADD_XOR_GATE_3,		// Add 3-input XOR gate
	ADD_XNOR_GATE_2,	// Add 2-input XNOR gate
	ADD_XNOR_GATE_3,	// Add 3-input XNOR gate



	ADD_Switch,			// Add Switch
	ADD_LED,			// Add LED
	ADD_CONNECTION,		// Add Wire Connection

	ADD_Label,			// Add Label to a Component or Connection
	EDIT_Label,			// Edit Label of a Component or Connection
	EDIT_Connection,	// Edit Input and Output of Connection
	Start_Simulation,   // Start the simulation 
	Create_TruthTable,	// Create Truth Table of the Circuit
	Change_Switch,		// Change Switch Status in Simulation Mode
	Check_Validation,    // Check all pins are connected and no component is floating
	Inspect_Value,       // Inspect the value of any pin or connection

	SELECT,				// Select a Component or Connection

	MOVE,				// Move a Component or Connection
	DEL,				// Delete a Component or Connection


	COPY,				// Copy a component without connections
	CUT,				// Cut a component and its connections
	PASTE,				// Paste a copied or cut component


	SAVE,				// Save the whole Circuit to a file
	LOAD,				// Load a Circuit from a file

	UNDO,				// Undo the last Action performed
	REDO,				// Redo the last Action canceled

	DSN_MODE,			// Switch to Design mode
	SIM_MODE,			// Switch to Simulation mode

	// --- ADD THIS ACTION TYPE ---
	PROBE,			// Probing Action
	// --------------------------
	DESIGN_MODE,	// Switch back to design mode
	// --------------------------

	EXIT,				// Exit the application

	STATUS_BAR,			// A click on the status bar

	DSN_TOOL,			// A click on an empty place in the design tool bar
	SIM_TOOL			// A click on an empty place in the simulation tool bar

};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};


enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_AND2,           // Add a 2 input AND gate
	ITM_AND3,           // Add a 3 input AND gate
	ITM_NAND2,          // Add a 2 input NAND gate
	ITM_NAND3,          // Add a 3 input NAND gate
	ITM_OR2,            // Add a 2 input OR gate
	ITM_OR3,            // Add a 3 input OR gate
	ITM_NOR2,           // Add a 2 input NOR gate
	ITM_NOR3,           // Add a 3 input NOR gate
	ITM_XOR2,           // Add a 2 input XOR gate 
	ITM_XOR3,           // Add a 3 input XOR gate
	ITM_XNOR2,          // Add a 2 input XNOR gate
	ITM_XNOR3,          // Add a 3 input XNOR gate
	ITM_BUFF,			// Add a Buffer
	ITM_INV,			// Add an Inverter

	ITM_SWITCH,         // Add a Switch
	ITM_LED,            // Add a Led    
	ITM_CONNECTION,     // Add a Connection

	ITM_ADD_LABEL,      // Add Label
	ITM_EDIT_LABEL,     // Edit label
	ITM_EDIT_CONNECTION, // Edit Connection INP or OUT

	ITM_COPY,			// Copy a component
	ITM_CUT,			// Cut a component
	ITM_PASTE,          // Paste a component

	ITM_SELECT,	        // Select component(s)
	ITM_MOVE,			// Move component(s)
	ITM_DEL,			// Delete component(s)

	ITM_SAVE,			// Save circuit
	ITM_LOAD,			// Load circuit

	ITM_UNDO,			// Undo last action
	ITM_REDO,			// Redo last action

	ITM_SIM_MODE,		// Switch to Simulation mode

	ITM_EXIT,			// Exit the application

	ITM_DSN_CNT			// Must be last (count of items)
};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_SIM,			  // Start simulation
	ITM_TRUTH,			  // Truth table
	ITM_SWITCH_CHANGE,	  // Change switch state
	ITM_CHECK_VALIDATION, // Check Validation of components
	ITM_INSPECT_VALUE,     // Inspect the value of pins or components
	ITM_DSN_MODE,		  // Return to design mode


	ITM_SIM_CNT			  // Count of simulation menu items (must be last)
};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5,
	OR2_FANOUT = 5,
	NAND2_FANOUT = 5,
	NOR2_FANOUT = 5,
	XOR2_FANOUT = 5,
	XNOR2_FANOUT = 5,
	AND3_FANOUT = 5,
	OR3_FANOUT = 5,
	NAND3_FANOUT = 5,
	NOR3_FANOUT = 5,
	XOR3_FANOUT = 5,
	XNOR3_FANOUT = 5,
	BUFF_FANOUT = 5,
	INV_FANOUT = 5,
	SWITCH_FANOUT = 5,
	LED_FANOUT = 0     // LED does not drive outputs
};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1, y1, x2, y2;
};

#ifndef NULL
#define NULL 0
#endif

#endif