#pragma once
#ifndef _XNOR2_H
#define _XNOR2_H
#include "Components\Gate.h"
#include <fstream> 
#include <string>
/*
  Class XNOR2
  -----------
  represent the 2-input XNOR gate
*/



class XNOR2 :public Gate
{
public:
	XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the XNOR2 gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

	virtual void save(std::ofstream& outfile, int compid) const;
	virtual void load(std::ifstream& infile);

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual OutputPin* GetOutputPin();
	virtual InputPin* GetInputPin(int n);
	// Clone function for Copy & Paste
	virtual Component* Clone() const override;

};

#endif