#include "BUFF.h"
#include <fstream> 
#include <string>

BUFF::BUFF(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void BUFF::Operate()
{
	//caclulate the output status
	//Add you code here
	if (GetInputPinStatus(1) == HIGH)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);

}


// Function Draw
// Draws BUFF gate
void BUFF::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.

	pOut->DrawBUFF(m_GfxInfo, isSelected);

}



//void BUFF::Save(std::ofstream& outfile, int compID) const 
//{
//    
//    const_cast<BUFF*>(this)->SetID(compID);
//
//    outfile << "BUFF\t";
//    outfile << compID << "\t";
//    outfile << GetLabel() << "\t";
//
//    
//    outfile << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << std::endl;
//}
//
//void BUFF::Load(std::ifstream& infile) 
//{
//   
//    int id;
//    infile >> id;
//    SetID(id);
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
int BUFF::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int BUFF::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BUFF::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
OutputPin* BUFF::GetOutputPin()
{
	return &m_OutputPin; // member of type OutputPin
}


InputPin* BUFF::GetInputPin(int n)
{
	if (n >= 1 && n <= 2)
		return &m_InputPins[n - 1]; // m_InputPins[0..1]
	return nullptr; // invalid index
}



Component* BUFF::Clone() const
{
	return new BUFF(*this);  // uses copy constructor
}