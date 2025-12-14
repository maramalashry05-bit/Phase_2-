#include "Component.h"
#include <string>

int Component::NextAvailableID = 1;

Component::Component(const GraphicsInfo &r_GfxInfo)
	:m_GfxInfo(r_GfxInfo),
		isSelected(false),
		m_ID(NextAvailableID++)
{
	
}


Component::Component() 
	: isSelected(false),
	m_ID(NextAvailableID++)
{ 
	
}

void Component::ResetIDCounter()
{
	// Resets the counter to 1, ready for loading a new circuit
	NextAvailableID = 1;
}


GraphicsInfo Component::GetGraphicsInfo()
{
	return m_GfxInfo;
}


	void Component:: Setselected(bool s) 
	{ 
		isSelected = s;
	}
	bool Component :: Getselected() const 
	{
		return isSelected;
	}

	bool Component::IsInside(int x, int y) {
		if (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 &&
			y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2) {
			return true;
		}
		return false;
	}



Component::~Component()
{}

