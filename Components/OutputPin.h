#ifndef _OUTPUTPIN_H
#define _OUTPUTPIN_H

#include "Pin.h"
class Connection;    // Forward class declaration
class Component;     // Forward declaration to fix C2061/C2065 errors

class OutputPin: public Pin
{
private:
    Connection* m_Connections[MAX_CONNS];
    int m_FanOut;
    int m_Conn;

    Component* m_pComponent = nullptr; // Declare pointer to owning component

public:
    OutputPin(int r_FanOut);
    bool ConnectTo(Connection *r_Conn);

    void RemoveConnection(Connection* pConn);

    void setComponent(Component* pComp) { m_pComponent = pComp; } // Use declared member and parameter
    Component* getComponent() const { return m_pComponent; }
    int GetOutPinStatus();
    void SetOutPinStatus(int s);
    bool HasSpace() const;
    int getConnCount() const;
    Connection** getConnections();
    void UnconnectAll();
};

#endif