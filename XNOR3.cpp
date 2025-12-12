#include "XNOR3.h"

XNOR3::XNOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XNOR3::Operate()
{
	//caclulate the output status as the XNORing of the three input pins
	//Add you code here
	int count = 0;
	if (GetInputPinStatus(1) == HIGH) count++;
	if (GetInputPinStatus(2) == HIGH) count++;
	if (GetInputPinStatus(3) == HIGH) count++;

	if (count % 2 == 1)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);
}


// Function Draw
// Draws 3-input XNOR gate

void XNOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.

	pOut->DrawXNOR3(m_GfxInfo, isSelected);

}

//returns status of outputpin
int XNOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
OutputPin* XNOR3::GetOutputPin()
{
	return &m_OutputPin; // member of type OutputPin
}


InputPin* XNOR3::GetInputPin(int n)
{
	if (n >= 1 && n <= 2)
		return &m_InputPins[n - 1]; // m_InputPins[0..1]
	return nullptr; // invalid index
}

Component* XNOR3::Clone() const
{
	return new XNOR3(*this);  // uses copy constructor
}
