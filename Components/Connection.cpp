#include "Connection.h"
#include <fstream>

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)
	
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}

OutputPin* Connection::GetOutputPin()
{
	return NULL;
}

InputPin* Connection::GetInputPin(int n)
{
	return NULL;
}

void Connection::Save(std::ofstream& outfile, int compID) const
{

    int srcID = SrcPin->getComponent()->GetID();


    int dstID = DstPin->getComponent()->GetID();


	int pinNum = DstPin->getInputNumber();

    outfile << srcID << "\t";
    outfile << dstID << "\t";
    outfile << pinNum << std::endl;
}

void Connection::Load(std::ifstream& infile)
{

}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	
		pOut->DrawConnection(m_GfxInfo,isSelected);
	
}


int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}
