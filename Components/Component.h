#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include "OutputPin.h"
#include "InputPin.h"
#include "../Label.h"

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	Label m_Label;
	
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	bool isSelected;
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	void Setselected(bool s);
	bool Getselected() const;
	bool IsInside(int x , int y );
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1
	virtual OutputPin* GetOutputPin()=0;
	virtual InputPin* GetInputPin(int n)=0;
	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	GraphicsInfo GetGraphicsInfo();
	virtual Component* Clone() const = 0;  // pure virtual, each gate implements it
	void SetGraphicsInfo(const GraphicsInfo& g) { m_GfxInfo = g; }
	
	//Label Functions
	void SetLabel(const std::string& text) { m_Label.SetText(text); }
	const std::string& GetLabel() const { return m_Label.GetText(); }
	bool isLapelEmp() { return m_Label.Empty(); };
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif


