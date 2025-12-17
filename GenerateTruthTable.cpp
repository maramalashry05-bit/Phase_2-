//#include "GenerateTruthTable.h"
//#include "Switch.h"
//#include "LED.h"
//#include <iostream>
//#include <cmath>
//
//GenerateTruthTable::GenerateTruthTable(ApplicationManager* pApp)
//    : Action(pApp) {
//}
//
//void GenerateTruthTable::Execute()
//{
//    Switch* inputs[MAX_INPUTS];
//    LED* outputs[MAX_OUTPUTS];
//    int nInputs = 0;
//    int nOutputs = 0;
//
//    int compCount = pManager->GetComponentCount();
//
//    // Separate switches and LEDs
//    for (int i = 0; i < compCount; i++) {
//        Component* comp = pManager->Getcomponent(i);
//        if (Switch* sw = dynamic_cast<Switch*>(comp)) {
//            if (nInputs < MAX_INPUTS) inputs[nInputs++] = sw;
//        }
//        else if (LED* led = dynamic_cast<LED*>(comp)) {
//            if (nOutputs < MAX_OUTPUTS) outputs[nOutputs++] = led;
//        }
//    }
//
//    if (nInputs == 0 || nOutputs == 0) {
//        pManager->GetOutput()->PrintMsg("No switches or LEDs found for truth table!");
//        return;
//    }
//
//    int totalCombinations = static_cast<int>(pow(2, nInputs));
//
//    std::ofstream outFile;
//    bool useFile = (nInputs > 5); // save to file if inputs > 5
//    if (useFile) {
//        outFile.open("TruthTable.txt");
//        if (!outFile.is_open()) return;
//    }
//
//    // Print header
//    auto printHeader = [&](std::ostream& os) {
//        for (int i = 0; i < nInputs; i++) os << "I" << i + 1 << "\t";
//        for (int i = 0; i < nOutputs; i++) os << "O" << i + 1 << "\t";
//        os << "\n";
//        };
//
//    if (useFile) printHeader(outFile);
//    else printHeader(std::cout);
//
//    // Loop through all combinations
//    for (int c = 0; c < totalCombinations; c++) {
//        // Set inputs using pow
//        for (int i = 0; i < nInputs; i++) {
//            int power = static_cast<int>(pow(2, nInputs - i - 1));
//            bool state = (c / power) % 2;
//            inputs[i]->SetState(state);
//        }
//
//        // Simulate the circuit
//        pManager->SimulateCircuit();
//
//        // Print line
//        auto printLine = [&](std::ostream& os) {
//            for (int i = 0; i < nInputs; i++) os << inputs[i]->GetState() << "\t";
//            for (int i = 0; i < nOutputs; i++) os << outputs[i]->GetOutPinStatus() << "\t";
//            os << "\n";
//            };
//
//        if (useFile) printLine(outFile);
//        else printLine(std::cout);
//    }
//
//    if (useFile) {
//        outFile.close();
//        pManager->GetOutput()->PrintMsg("Truth table saved to TruthTable.txt");
//    }
//    else {
//        pManager->GetOutput()->PrintMsg("Truth table displayed in console (<=5 inputs)");
//    }
//}
//