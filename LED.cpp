#include "LED.h"
#include <fstream> 
#include <string>

LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut) : Gate(1, 0) , m_isOn(false)
{
    m_GfxInfo.x1 = r_GfxInfo.x1;
    m_GfxInfo.y1 = r_GfxInfo.y1;
    m_GfxInfo.x2 = r_GfxInfo.x2;
    m_GfxInfo.y2 = r_GfxInfo.y2;
}

void LED::Operate()
{
    // LED does not drive any outputs. Its state is purely visual:
    // read its single input pin and update the internal visual flag.
    if (GetInputPin(1) != nullptr)
        m_isOn = (GetInputPinStatus(1) == HIGH);
    else
        m_isOn = false;
}

// Function Draw
// Draws LED
void LED::Draw(Output* pOut)
{
    // Pass the current ON/OFF state to the output drawing routine.
    pOut->DrawLED(m_GfxInfo, m_isOn, isSelected);
}

void LED::Save(std::ofstream& outfile, int compID) const 
{
   
    const_cast<LED*>(this)->SetID(compID);

    outfile << "LED\t";
    outfile << compID << "\t";
    outfile << GetLabel() << "\t";

    outfile << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << std::endl;
}

void LED::Load(std::ifstream& infile) 
{
   
    int id;
    infile >> id;
    SetID(id);

    
    std::string label;
    infile >> label;
    SetLabel(label);

    
    infile >> m_GfxInfo.x1 >> m_GfxInfo.y1;

    
    m_isOn = false;
}


// LED has no output pin -> return -1 or nullptr as appropriate
int LED::GetOutPinStatus()
{
    return -1;
}

OutputPin* LED::GetOutputPin()
{
    return nullptr;
}

// Single input pin handling
int LED::GetInputPinStatus(int n)
{
    if (n == 1 && GetInputPin(1) != nullptr)
        return m_InputPins[0].getStatus();
    return -1;
}

void LED::setInputPinStatus(int n, STATUS s)
{
    if (n == 1)
        m_InputPins[0].setStatus(s);
}

InputPin* LED::GetInputPin(int n)
{
    if (n == 1)
        return &m_InputPins[0];
    return nullptr;
}

Component* LED::Clone() const
{
    return new LED(*this);
}