#pragma once
#pragma once
#ifndef _XOR3_H
#define _XOR3_H
#include "Components\Gate.h"
#include <fstream> 
#include <string>
/*
  Class XOR3
  -----------
  represent the 3-input XOR3 gate
*/



class XOR3 :public Gate
{
public:
	XOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the XOR3 gate
	virtual void Draw(Output* pOut);	//Draws 3-input gate

	virtual void save(std::ofstream& outfile, int compID) const override;
	virtual void load(std::ifstream& infile) override;

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual OutputPin* GetOutputPin();
	virtual InputPin* GetInputPin(int n);

	// Clone function for Copy & Paste
	virtual Component* Clone() const override;

};

#endif