#include <iostream>
#include "part_view.hpp" 

void PartView::AskPartType() {
    std::cout << "Choose a part type: " << std::endl << "1. Torso" << std::endl
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
    std::cout << part->ToString() << std::endl;
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
