//#include "AddConnection.h"
//#include "ApplicationManager.h"
//#include "Components\Connection.h"
//#include "Components\Gate.h"
//
//ActionAddConnection::ActionAddConnection(ApplicationManager* pApp)
//    : Action(pApp)
//{
//    SrcComp = nullptr;
//    DstComp = nullptr;
//    SrcPinIndex = 0;
//    DstPinIndex = 0;
//}
//
//void ActionAddConnection::ReadActionParameters()
//{
//    Output* pOut = pManager->GetOutput();
//    Input* pIn = pManager->GetInput();
//
//    int x1, y1, x2, y2;
//
//    // 1. Select source gate
//    pOut->PrintMsg("Click on the output gate...");
//    pIn->GetPointClicked(x1, y1);
//    SrcComp = pManager->GetComponent(x1, y1);
//
//    if (!SrcComp) {
//        pOut->PrintMsg("Invalid source gate.");
//        return;
//    }
//
//    // 2. Select destination gate
//    pOut->PrintMsg("Click on the input gate...");
//    pIn->GetPointClicked(x2, y2);
//    DstComp = pManager->GetComponent(x2, y2);
//
//    if (!DstComp) {
//        pOut->PrintMsg("Invalid destination gate.");
//        return;
//    }
//
//    // Determine which input pin was clicked for the destination gate
//    DstPinIndex = DstComp->GetInputPinIndexAt(x2, y2);
//
//    // Fill GInfo
//    GInfo.x1 = x1;
//    GInfo.y1 = y1;
//    GInfo.x2 = x2;
//    GInfo.y2 = y2;
//
//    pOut->ClearStatusBar();
//}
//
//void ActionAddConnection::Execute()
//{
//    ReadActionParameters();
//
//    if (!SrcComp || !DstComp)
//        return;
//
//    OutputPin* pOutPin = SrcComp->GetOutputPin();
//    InputPin* pInPin = DstComp->GetInputPin(DstPinIndex);
//
//    if (!pOutPin || !pInPin) {
//        pManager->GetOutput()->PrintMsg("Cannot connect these components!");
//        return;
//    }
//
//    // Create the connection
//    Connection* pConn = new Connection(GInfo, pOutPin, pInPin);
//
//    // Add to application manager
//    pManager->AddComponent(pConn);
//
//    // Connect electrically
//    pOutPin->ConnectTo(pConn);
//
//    pManager->GetOutput()->PrintMsg("Connection created!");
//}
//
//void ActionAddConnection::Undo()
//{
//    
//}
//
//void ActionAddConnection::Redo()
//{
//    
//}
