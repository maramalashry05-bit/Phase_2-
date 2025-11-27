#include "Output.h"
#include <iostream>


Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
void Output::ClearToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\Menu_AND3.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_NAND2.jpg";
	MenuItemImages[ITM_NAND3] = "images\\Menu\\Menu_NAND3.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_OR3] = "images\\Menu\\Menu_OR3.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_NOR2.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\Menu_NOR3.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\Menu_XOR2.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\Menu_XOR3.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\Menu_XNOR2.jpg";
	MenuItemImages[ITM_XNOR3] = "images\\Menu\\Menu_XNOR3.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\Menu_Switch.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\Menu_Led.jpg";
	MenuItemImages[ITM_CONNECTION] = "images\\Menu\\Menu_Connection.jpg";
	MenuItemImages[ITM_ADD_LABEL] = "images\\Menu\\Menu_Add_Label.jpg";
	MenuItemImages[ITM_EDIT_LABEL] = "images\\Menu\\Menu_Edit_Label.jpg";
	MenuItemImages[ITM_SELECT] = "images\\Menu\\Menu_Select.jpg";
	MenuItemImages[ITM_MOVE] = "images\\Menu\\Menu_Move.jpg";
	MenuItemImages[ITM_DEL] = "images\\Menu\\Menu_Delete.jpg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\Menu_Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\Menu_Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\Menu_Paste.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\Menu_Redo.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\Menu_Load.jpg";
	MenuItemImages[ITM_SIM_MODE] = "images\\Menu\\Menu_Simulation_Mode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_SIM] = "images\\Menu\\Menu_Start_Simulation.jpg";
	MenuItemImages[ITM_TRUTH] = "images\\Menu\\Menu_Create_Truth_Table.jpg";
	MenuItemImages[ITM_SWITCH_CHANGE] = "images\\Menu\\Menu_Change_Switch.jpg";
	MenuItemImages[ITM_CHECK_VALIDATION] = "images\\Menu\\Menu_Check_Validation.jpg";
	MenuItemImages[ITM_INSPECT_VALUE] = "images\\Menu\\Menu_Inspect_Value.jpg";
	MenuItemImages[ITM_DSN_MODE] = "images\\Menu\\Menu_Design_Mode.jpg";
	ClearToolBar();


	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

//TODO: Add similar functions to draw all components
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND3.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND3_Width, UI.AND3_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND2.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}

void Output::DrawNAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND3.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND3_Width, UI.NAND3_Height);
}


void Output::DrawSwitch(GraphicsInfo r_GfxInfo, bool selected) const
{


	const int SWITCH_WIDTH = 50;  // width of switch rectangle
	const int SWITCH_HEIGHT = 30; // height of switch rectangle


	// Determine color for selection
	color drawColor = selected ? RED : BLACK;
	color fillColor = LIGHTGRAY;
	color nodeColor = selected ? RED : GREEN;

	// Set pen and brush
	pWind->SetPen(drawColor, 3);   // border thickness 3
	pWind->SetBrush(fillColor);

	// Draw the rectangle representing the switch
	int x = r_GfxInfo.x1;  // top-left x
	int y = r_GfxInfo.y1;  // top-left y
	int x2 = x + SWITCH_WIDTH;
	int y2 = y + SWITCH_HEIGHT;

	pWind->DrawRectangle(x, y, x2, y2);

	// Draw the small toggle circle inside rectangle
	int circleRadius = 10;
	int circleX = x2 - circleRadius - 5;
	int circleY = y + SWITCH_HEIGHT / 2;

	pWind->SetBrush(nodeColor);
	pWind->DrawCircle(circleX, circleY, circleRadius);
}




void Output::DrawINV(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_INV_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_INV.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.INV_Width, UI.INV_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR3.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR3_Width, UI.XOR3_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR2.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR2_Width, UI.XNOR2_Height);
}

void Output::DrawXNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR3.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR3_Width, UI.XNOR3_Height);
}

void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

void Output::DrawOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR3.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR3_Width, UI.OR3_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR2_Width, UI.NOR2_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR3.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR3_Width, UI.NOR3_Height);
}

void Output::DrawBUFF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_BUFF_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_BUFF.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.BUFF_Width, UI.BUFF_Height);
}

void Output::DrawLED(GraphicsInfo r_GfxInfo, bool isOn, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\LED_Hi.jpg";
	else
	{
		if (isOn)
			GateImage = "Images\\Gates\\LED_On.jpg";
		else
			GateImage = "Images\\Gates\\LED_Off.jpg";
	}



	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);

}



void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{

	//TODO: Add code to draw connection




	color drawcolor = selected ? RED : BLACK;
	pWind->SetPen(drawcolor, 3);

	int x1 = r_GfxInfo.x1;
	int y1 = r_GfxInfo.y1;
	int x2 = r_GfxInfo.x2;
	int y2 = r_GfxInfo.y2;

	if (y1 == y2)
	{
		// Straight
		pWind->DrawLine(x1, y1, x2, y2);
	}
	else
	{
		// broken (horizontal ? vertical ? horizontal)
		int xm = (x1 + x2) / 2;
		pWind->DrawLine(x1, y1, xm, y1);
		pWind->DrawLine(xm, y1, xm, y2);
		pWind->DrawLine(xm, y2, x2, y2);

	}
}




Output::~Output()
{
	delete pWind;
}
