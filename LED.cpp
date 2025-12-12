#include "LED.h"

LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void LED::Operate()
{
	//??? 
}


// Function Draw
// Draws LED
void LED::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.

	pOut->DrawLED(m_GfxInfo, false ,isSelected);

}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return -1;
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

OutputPin* LED::GetOutputPin()
{
	return &m_OutputPin; // member of type OutputPin
}


InputPin* LED::GetInputPin(int n)
{
	if (n >= 1 && n <= 2)
		return &m_InputPins[n - 1]; // m_InputPins[0..1]
	return nullptr; // invalid index
}

Component* LED::Clone() const
{
	return new LED(*this);  // uses copy constructor
}