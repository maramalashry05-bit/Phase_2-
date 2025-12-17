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
    if (GetInputPin(0) != nullptr)
        m_isOn = (GetInputPinStatus(0) == HIGH);
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

void LED::save(std::ofstream& outfile, int compid) const 
{
   
   
    outfile << "led\t";
    outfile << compid << "\t";
    outfile << GetLabel() << "\t";

    outfile << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << std::endl;
}

void LED::load(std::ifstream& infile) 
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
    if (n == 0 && GetInputPin(1) != nullptr)
        return m_InputPins[0].getStatus();
    return -1;
}

void LED::setInputPinStatus(int n, STATUS s)
{
    if (n == 0)
        m_InputPins[0].setStatus(s);
}

InputPin* LED::GetInputPin(int n)
{
    if (n == 0)
        return &m_InputPins[0];
    return nullptr;
}

Component* LED::Clone() const
{
    return new LED(*this);
}