#pragma once
#ifndef _NAND2_H
#define _NAND2_H
#include "Components\Gate.h"
#include <fstream> 
#include <string>

/*
  Class NAND2
  -----------
  represent the 2-input NAND gate
*/



class NAND2 :public Gate
{
public:
	NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the NAND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

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