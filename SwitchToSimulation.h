//#include "SWITCHTOSIM.h"
//
////======================================================================================//
////								Constructor												//
////======================================================================================//
//
//SwitchToSIM::SwitchToSIM(ApplicationManager* pApp) : Action(pApp)
//{
//	pOut = pApp->GetOutput();
//	pIn = pApp->GetInput();
//}
//
////======================================================================================//
////								Action Execution Functions								//
////======================================================================================//
//
//// ----------------- Read Action Parameters -----------------
//void SwitchToSIM::ReadActionParameters()
//{
//	// No parameters needed for switching modes
//}
//
//// ----------------- Execute Action -----------------
//void SwitchToSIM::Execute()
//{
//	pOut->CreateSimulationToolBar();
//	pOut->PrintMsg("Switched to Simulation Mode.");
//}