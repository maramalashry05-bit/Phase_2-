#pragma once
#ifndef LED_H
#define LED_H
#include "Components\Gate.h"

/*
  Class LED
  -----------
  represent the LED
  
  */



class LED :public Gate
{
private:
    bool m_isOn; // Internal state to represent if the LED is ON or OFF

public:
	LED(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of LED
	virtual void Draw(Output* pOut);	//Draws 1-input LED

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual OutputPin* GetOutputPin();
	virtual InputPin* GetInputPin(int n);
	// Clone function for Copy & Paste
	virtual Component* Clone() const override;

};

#endif