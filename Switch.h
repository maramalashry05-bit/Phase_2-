#ifndef SWITCH_H
#define SWITCH_H



#include "Components\Gate.h"
class Switch : public Gate
{
private:
  
    bool m_State;           // ON = true, OFF = false

public:
    Switch(const GraphicsInfo& r_GfxInfo);

    virtual void Operate() override;        // Sets output pin according to state
    virtual void Draw(Output* pOut) override; // Draw the switch on GUI

    virtual int GetOutPinStatus();          // Return output status
    virtual int GetInputPinStatus(int n);   // Switch has no input ? return -1

    virtual void setInputPinStatus(int n, STATUS s); // Do nothing, no input pin

    virtual OutputPin* GetOutputPin();
    virtual InputPin* GetInputPin(int n);   // Return nullptr, no input

    void Toggle();                           // Change state ON/OFF
    bool GetState() const;
    void SetState(bool state);

    // Clone function for copy/paste
   /* virtual Component* Clone() const override;*/
};

#endif
