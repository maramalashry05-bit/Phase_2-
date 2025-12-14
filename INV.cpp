#include "INV.h"
#include <fstream> 
#include <string>

INV::INV(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void INV::Operate()
{
	//caclulate the output status
	//Add you code here
	if (GetInputPinStatus(1) == HIGH)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);

}


// Function Draw
// Draws INV gate
void INV::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.

	pOut->DrawINV(m_GfxInfo, isSelected);

}

//void INV::Save(std::ofstream& outfile, int compID) const 
//{
//    
//    const_cast<INV*>(this)->SetID(compID);
//
//    outfile << "INV\t";
//    outfile << compID << "\t";
//    outfile << GetLabel() << "\t";
//
//   
//    outfile << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << std::endl;
//}
//
//void INV::Load(std::ifstream& infile) 
//{
//    
//    int id;
//    infile >> id;
//    SetID(id);
//
//  
//    std::string label;
//    infile >> label;
//    SetLabel(label);
//
//  
//    infile >> m_GfxInfo.x1 >> m_GfxInfo.y1;
//
//   
//}


//returns status of outputpin
int INV::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int INV::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void INV::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
OutputPin* INV::GetOutputPin()
{
	return &m_OutputPin; // member of type OutputPin
}


InputPin* INV::GetInputPin(int n)
{
	if (n >= 1 && n <= 2)
		return &m_InputPins[n - 1]; // m_InputPins[0..1]
	return nullptr; // invalid index
}


Component* INV::Clone() const
{
	return new INV(*this);  // uses copy constructor
}