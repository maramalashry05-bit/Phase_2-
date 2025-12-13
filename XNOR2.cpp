#include "XNOR2.h"
#include <fstream> 
#include <string>

XNOR2::XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XNOR2::Operate()
{
	//caclulate the output status as the XNOR2ing of the three input pins
	//Add you code here
	if (GetInputPinStatus(1) == GetInputPinStatus(2))
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);

}


// Function Draw
// Draws 2-input XNOR gate

void XNOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.

	pOut->DrawXNOR2(m_GfxInfo, isSelected);

}

void XNOR2::Save(std::ofstream& outfile, int compID) const 
{
   
    const_cast<XNOR2*>(this)->SetID(compID);

   
    outfile << "XNOR2\t";
    outfile << compID << "\t";
    outfile << GetLabel() << "\t";

    outfile << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << std::endl;
}

void XNOR2::Load(std::ifstream& infile) 
{
  
    int id;
    infile >> id;
    SetID(id);

   
    std::string label;
    infile >> label;
    SetLabel(label);

   
    infile >> m_GfxInfo.x1 >> m_GfxInfo.y1;

}

//returns status of outputpin
int XNOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
OutputPin* XNOR2::GetOutputPin()
{
	return &m_OutputPin; // member of type OutputPin
}


InputPin* XNOR2::GetInputPin(int n)
{
	if (n >= 1 && n <= 2)
		return &m_InputPins[n - 1]; // m_InputPins[0..1]
	return nullptr; // invalid index
}


Component* XNOR2::Clone() const
{
	return new XNOR2(*this);  // uses copy constructor
}