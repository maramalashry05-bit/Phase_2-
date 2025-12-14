#pragma once
#ifndef BUFF_H
#define BUFF_H
#include "Components\Gate.h"
#include <fstream> 
#include <string>

/*
  Class BUFF
  -----------
  represent the Buffer gate
*/



class BUFF :public Gate
{
public:
	BUFF(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the BUFF gate
	virtual void Draw(Output* pOut);	//Draws 1-input gate

	/*virtual void Save(std::ofstream& outfile, int compID) const;
	virtual void Load(std::ifstream& infile);*/

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual OutputPin* GetOutputPin();
	virtual InputPin* GetInputPin(int n);
	// Clone function for Copy & Paste
	virtual Component* Clone() const override;

};

#endif