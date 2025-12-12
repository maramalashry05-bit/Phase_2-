#pragma once
#include "Pin.h"

class Connection; // Forward declaration
class Component; // Forward declaration (if not already present)

class InputPin : public Pin
{
private:
    Connection* m_Connection; // Pointer to the connection attached to this pin
    Component* m_pComponent;  // Pointer to the owning component
    int m_InputNumber = -1;
    bool Connected = false;
public:
    InputPin();

    // Attach a connection to this input pin
    void setConnection(Connection* pConn);

    // Get the connection attached to this input pin
    Connection* getConnection() const;

    // Remove the connection from this input pin
    void RemoveConnection();

    // Set the component that owns this pin
    void setComponent(Component* pComp) { m_pComponent = pComp; }

    // Get the component that owns this pin
    Component* getComponent() const { return m_pComponent; }

    // Set the input number (index) for this pin
    void setInputNumber(int n) { m_InputNumber = n; }

    // Get the input number (index) for this pin
    int getInputNumber() const { return m_InputNumber; }

    // Check if the pin is connected
    bool isConnected() const;
};