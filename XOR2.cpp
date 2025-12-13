#include "XOR2.h"
#include <fstream> 
#include <string>

XOR2::XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR2::Operate()
{
		// Calculate the output status as the XORing of the two input pins
		// XOR is true only when inputs are different
		if (GetInputPinStatus(1) != GetInputPinStatus(2))
			m_OutputPin.setStatus(HIGH);
		else
			m_OutputPin.setStatus(LOW);
	
}


// Function Draw
// Draws 2-input XOR gate
void XOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.

	pOut->DrawXOR2(m_GfxInfo, isSelected);

}

void XOR2::Save(std::ofstream& outfile, int compID) const 
{
    const_cast<XOR2*>(this)->SetID(compID);

  
    outfile << "XOR2\t";
    outfile << compID << "\t";
    outfile << GetLabel() << "\t";

    
    outfile << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << std::endl;
}

void XOR2::Load(std::ifstream& infile)
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
int XOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
OutputPin* XOR2::GetOutputPin()
{
	return &m_OutputPin; // member of type OutputPin
}


InputPin* XOR2::GetInputPin(int n)
{
	if (n >= 1 && n <= 2)
		return &m_InputPins[n - 1]; // m_InputPins[0..1]
	return nullptr; // invalid index
}

Component* XOR2::Clone() const
{
	return new XOR2(*this);  // uses copy constructor
}