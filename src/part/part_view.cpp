#include "part/part_view.hpp" 

#include <iostream>

void PartView::AskPartType() {
    std::cout << std::endl << "Choose a part type: " << std::endl << "1. Torso" 
        << std::endl
        << "2. Head" << std::endl << "3. Arm" << std::endl << "4. Locomotor"
        << std::endl << "5. Battery" << std::endl;
}

void PartView::AskPartName() {
    std::cout << "Enter a part name: " << std::endl;
}

void PartView::AskPartNumber() {
    std::cout << "Enter a part number: " << std::endl;
}

void PartView::AskPartWeight() {
    std::cout << "Enter the part weight: " << std::endl;
}

void PartView::AskPartCost() {
    std::cout << "Enter the part cost: " << std::endl;
}

void PartView::AskPartDescription() {
    std::cout << "Enter a part description: " << std::endl;
}

void PartView::DisplayPart(std::unique_ptr<Part> const &part) {
    std::cout << "Part Information" << std::endl << "*********************" 
        << std::endl << part->ToString() << std::endl;
}

void PartView::AskForKiloWattHours() {
    std::cout << "Enter energy contained in kilowatt hours: " << std::endl;
}

void PartView::AskForMaxMphSpeed() {
    std::cout << "Enter maximum speed in mph: " << std::endl;
}

void PartView::AskForPowerConsumedWatts() {
   std::cout << "Enter power consumed in watts: " << std::endl;
}


void PartView::AskForBatteryCompartmentSize() {
   std::cout << "Enter the number of battery compartments (1-3): " << std::endl;
}

void PartView::DisplayParts(std::vector<std::unique_ptr<Part>> const &parts) {
    int enumerate = 1;
    std::cout << std::endl << "Parts List" << std::endl 
        << "*************************" << std::endl;
    for (std::unique_ptr<Part> const &part : parts) {
        std::cout << enumerate++ << "." << std::endl;
        std::cout << part->ToString();
    }

    std::cout << std::endl;
}
