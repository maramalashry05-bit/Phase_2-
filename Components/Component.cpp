#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
	isSelected = false;
}



GraphicsInfo Component::GetGraphicsInfo()
{
	return m_GfxInfo;
}

Component::Component()
 { 
	isSelected = false;
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

