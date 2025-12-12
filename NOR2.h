#pragma once
#ifndef _NOR2_H
#define _NOR2_H
#include "Components\Gate.h"
/*
  Class NOR2
  -----------
  represent the 2-input NOR gate
*/



class NOR2 :public Gate
{
public:
	NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the NOR2 gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual OutputPin* GetOutputPin();
	virtual InputPin* GetInputPin(int n);
	// Clone function for Copy & Paste
	virtual Component* Clone() const override;


};

#endif
