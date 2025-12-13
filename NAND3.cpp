#include "NAND3.h"
#include <fstream> 
#include <string>

NAND3::NAND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NAND3::Operate()
{
	//caclulate the output status as the NANDing of the three input pins
	//Add you code here
	if (GetInputPinStatus(1) == HIGH && GetInputPinStatus(2) == HIGH && GetInputPinStatus(3) == HIGH)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);

}


// Function Draw
// Draws 3-input NAND gate
void NAND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	
		pOut->DrawNAND3(m_GfxInfo,isSelected);
	
}

void NAND3::Save(std::ofstream& outfile, int compID) const 
{
   
    const_cast<NAND3*>(this)->SetID(compID);

   
    outfile << "NAND3\t";
    outfile << compID << "\t";
    outfile << GetLabel() << "\t";

   
    outfile << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << std::endl;
}

void NAND3::Load(std::ifstream& infile) 
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
int NAND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
OutputPin* NAND3::GetOutputPin()
{
	return &m_OutputPin; // member of type OutputPin
}


InputPin* NAND3::GetInputPin(int n)
{
	if (n >= 1 && n <= 2)
		return &m_InputPins[n - 1]; // m_InputPins[0..1]
	return nullptr; // invalid index
}
Component* NAND3::Clone() const
{
	return new NAND3(*this);  // uses copy constructor
}
