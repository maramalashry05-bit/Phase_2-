#include "OutputPin.h"
#include "Connection.h"


OutputPin::OutputPin(int r_FanOut)
{
	m_Conn = 0;		//initially Pin is not connected to anything.
	m_FanOut = r_FanOut > MAX_CONNS ? MAX_CONNS : r_FanOut;	//set the fan out of the pin.
}

//Functionn ConnectTo:
//Connects the ouput pin the the passed connection if the fan out permits
//if the no. of connections is already equals to the fan out, no more connections can be created.
bool OutputPin::ConnectTo(Connection* r_Conn)
{
	if (m_Conn < m_FanOut)
	{
		m_Connections[m_Conn++] = r_Conn;	//add a new connection the the array of connections
		return true;
	}

	return false;	//can't connect to any more connections
}
// to get the output status
int OutputPin::GetOutPinStatus()
{
	return m_Status;
}
// to set output status 
void OutputPin::SetOutPinStatus(int s)
{
	m_Status == s;
}
// Check if  you can add more wires
bool OutputPin::HasSpace() const
{
	return (m_Conn < m_FanOut);
}

// Number of wires
int OutputPin::getConnCount() const
{
	return m_Conn;
}

// Give access to the array of connections
Connection** OutputPin::getConnections()
{
	return m_Connections;
}
// Remove a  connection from a pin
void OutputPin::RemoveConnection(Connection* r_Conn)
{
	for (int i = 0; i < m_Conn; i++)
	{
		if (m_Connections[i] == r_Conn)
		{
			// shift array left
			for (int j = i; j < m_Conn - 1; j++)
				m_Connections[j] = m_Connections[j + 1];

			m_Conn--;
			return;
		}
	}
}
// to unconnect all when deleting 
void OutputPin::UnconnectAll()
{
	for (int i = 0; i < m_Conn; i++)
		m_Connections[i]->setSourcePin(NULL);

	m_Conn = 0;
}

void OutputPin::setStatus(STATUS s) {
	m_Status = s;
}

STATUS OutputPin::getStatus() {
	return m_Status;
}