#include "Switch.h"




Switch::Switch(const GraphicsInfo& r_GfxInfo) :Gate(0, 1)
{
    m_GfxInfo.x1 = r_GfxInfo.x1;
    m_GfxInfo.y1 = r_GfxInfo.y1;
    m_GfxInfo.x2 = r_GfxInfo.x2;
    m_GfxInfo.y2 = r_GfxInfo.y2;
}


void Switch::Operate()
{
    // Output pin follows the switch state
    m_OutputPin.setStatus(m_State ? HIGH : LOW);
}

void Switch::Draw(Output* pOut)
{
    // Draw switch rectangle 
    pOut->DrawSwitch(m_GfxInfo, isSelected,m_State);
}


int Switch::GetOutPinStatus()
{
    return m_OutputPin.getStatus();
}

int Switch::GetInputPinStatus(int n)
{
    return -1; // Switch has no input
}

void Switch::setInputPinStatus(int n, STATUS s)
{
    // Nothing to do
}

OutputPin* Switch::GetOutputPin()
{
    return &m_OutputPin;
}

InputPin* Switch::GetInputPin(int n)
{
    return nullptr; // No input pins
}

void Switch::Toggle()
{
    m_State = !m_State;
    Operate(); // update output pin
}

bool Switch::GetState() const
{
    return m_State;
}

void Switch::SetState(bool state)
{
    m_State = state;
    Operate();
}

Component* Switch::Clone() const
{
    return new Switch(*this); // copy constructor
}
void Switch::save(std::ofstream& outfile, int compid) const
{


    outfile << "SWT\t";
    outfile << compid << "\t";
    outfile << GetLabel() << "\t";

    outfile << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << std::endl;
}

void Switch::load(std::ifstream& infile)
{

    int id;
    infile >> id;
    SetID(id);


    std::string label;
    infile >> label;
    SetLabel(label);


    infile >> m_GfxInfo.x1 >> m_GfxInfo.y1;


    m_State = false;
}