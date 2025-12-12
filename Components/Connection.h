#pragma once
#include "component.h"
#include "InputPin.h"
#include "OutputPin.h"

class Connection : public Component
{
	Component*	SrcCmpnt;	//Connection source component
	Component*	DstCmpnt;	//Connection Destination component
	
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
public:
	Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin, InputPin *pDstPin);

	virtual void Operate();	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut);	//for each component to Draw itself

	
	void setSourcePin(OutputPin *pSrcPin);
	void setDestPin(InputPin *pDstPin);
	OutputPin* getSourcePin();
	InputPin* getDestPin();


	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual OutputPin* GetOutputPin();
	virtual InputPin* GetInputPin(int n);

	// Implement missing pure virtuals from Component
	virtual Component* Clone() const override { return nullptr; } // Not needed for Connection, return nullptr

	virtual ~Connection() {}
};
