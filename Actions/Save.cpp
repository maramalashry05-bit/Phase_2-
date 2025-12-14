//#include "Save.h"
//#include "../ApplicationManager.h"
//#include "../GUI/Input.h"        
//#include "../GUI/Output.h"
//#include <fstream>
//#include <iostream> 
//
//Save::Save(ApplicationManager* pApp) : Action(pApp)
//{
//    FileName = "";
//}
//
//// Function to get the filename from the user
//void Save::ReadActionParameters()
//{
//    Output* pOut = pManager->GetOutput();
//    Input* pIn = pManager->GetInput();
//
//    pOut->PrintMsg("Action: Save Circuit. Enter filename to save to:");
//    // Assuming GetFileName() is a method in Input that takes an Output pointer
//    FileName = pIn->GetSrting(pOut);
//    pOut->ClearStatusBar();
//}
//
//void Save::Execute()
//{
//    ReadActionParameters();
//
//    // Check if the user cancelled the input
//    if (FileName.empty()) return;
//
//    std::ofstream OutFile;
//    // Append .txt extension and open the file
//    OutFile.open(FileName + ".txt", std::ios::out);
//
//    if (!OutFile.is_open())
//    {
//        pManager->GetOutput()->PrintMsg("Error: Could not open file for saving.");
//        return;
//    }
//
//    // Delegate the saving process to the Application Manager
//    pManager->SaveAll(OutFile);
//
//    OutFile.close();
//    pManager->GetOutput()->PrintMsg("Circuit saved successfully to " + FileName + ".txt");
//}
