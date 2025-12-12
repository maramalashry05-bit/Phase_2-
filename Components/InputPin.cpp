#include "InputPin.h"    
#include "Connection.h"  

// intialize new variables to the constructor 
InputPin::InputPin()
{
    m_pComponent = nullptr;
    m_Connection = nullptr;
    m_InputNumber = -1;
    m_Status = LOW;
    Connected = false;
}

// connection ( connected wire) handling 
void InputPin::setConnection(Connection* c)
{
    m_Connection = c;
    Connected = (c != nullptr);
    if (!c)
        m_InputNumber = -1;
}

Connection* InputPin::getConnection() const
{
    return m_Connection;
}

// pin index handling 

bool InputPin::isConnected() const
{
    return Connected;
}
void InputPin::RemoveConnection()
{
    m_Connection = nullptr;
    Connected = false;
    m_InputNumber = -1;
}