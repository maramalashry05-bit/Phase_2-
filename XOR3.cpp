#include "XOR3.h"
#include <fstream> 
#include <string>

XOR3::XOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR3::Operate()
{
	// Calculate the output status as the XORing of the three input pins
	// XOR is true when an odd number of inputs are HIGH
	int count = 0;
	if (GetInputPinStatus(1) == HIGH) count++;
	if (GetInputPinStatus(2) == HIGH) count++;
	if (GetInputPinStatus(3) == HIGH) count++;

	if (count % 2 == 1)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws 3-input XOR gate
void XOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.

	pOut->DrawXOR3(m_GfxInfo, isSelected);

}

void XOR3::Save(std::ofstream& outfile, int compID) const 
{
    
    const_cast<XOR3*>(this)->SetID(compID);

   
    outfile << "XOR3\t";
    outfile << compID << "\t";
    outfile << GetLabel() << "\t";

   
    outfile << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << std::endl;
}

void XOR3::Load(std::ifstream& infile) 
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
int XOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
OutputPin* XOR3::GetOutputPin()
{
	return &m_OutputPin; // member of type OutputPin
}


InputPin* XOR3::GetInputPin(int n)
{
	if (n >= 1 && n <= 2)
		return &m_InputPins[n - 1]; // m_InputPins[0..1]
	return nullptr; // invalid index
}

Component* XOR3::Clone() const
{
	return new XOR3(*this);  // uses copy constructor
}