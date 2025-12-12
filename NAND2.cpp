#include "NAND2.h"

NAND2::NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NAND2::Operate()
{
	//caclulate the output status as the NANDing of the two input pins
	//Add you code here
	if (GetInputPinStatus(1) == HIGH && GetInputPinStatus(2) == HIGH)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);

}


// Function Draw
// Draws 2-input NAND gate
void NAND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	
		pOut->DrawNAND2(m_GfxInfo,isSelected);
	
}

//returns status of outputpin
int NAND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
OutputPin* NAND2::GetOutputPin()
{
	return &m_OutputPin; // member of type OutputPin
}


InputPin* NAND2::GetInputPin(int n)
{
	if (n >= 1 && n <= 2)
		return &m_InputPins[n - 1]; // m_InputPins[0..1]
	return nullptr; // invalid index
}
Component* NAND2::Clone() const
{
	return new NAND2(*this);  // uses copy constructor
}
