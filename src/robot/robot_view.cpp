#include <iostream>
#include "robot_view.hpp"

void RobotView::AskModelName() {
    std::cout << "Enter a robot model name: " << std::endl;
}

void RobotView::AskModelNumber() {
    std::cout << "Enter  robot model number (integers only): " <<std::endl;
}

void RobotView::AskModelPrice() {
    std::cout << "Enter the robot model price in dollars: " << std::endl;
}

void RobotView::DisplayRobotModel(std::unique_ptr<Robot> const &robot) {
    std::cout << "Robot Information" << std::endl << "**********************"
        << std::endl << robot->ToString() << std::endl;
}

void RobotView::DisplayPartSelectionMenu() {
    std::cout << "Part Selection" << std::endl << "**********************" 
        << "1. Add Part (by Part number)" << std::endl 
        << "2. Reset Part Selection" << std::endl << "3. Create Robot Model"
        << std::endl << "4. Quit to main menu" << std::endl;w
}

void RobotView::DisplayPartSelectionSuccess() {
    std::cout << "Part successfully added to robot model" << std::endl;
}

void RobotView::DisplayPartSelectionFailure() {
    std::cout << "Part selection cannot be added to robot model. " << std::endl;
}

void RobotView::DisplayBadPartSelectionInput() {
    std::cout << "Invalid part selection menu input." << std::endl;
}

void RobotView::DisplayRobotParts(std::unique_ptr<Robot> const &robot) {
    std::cout << "Currently Selected Parts" << std::endl
        << "*****************************" << std::endl;
    int index = 1;
    for (std::unique_ptr<Part> const &part : robot->GetParts()) {
        std::cout << index++ << ". " << "\tPart Number: " << part->GetPartNumber()
           << std::endl << "\tPart Type: " << part->GetPartTypeString() << std::endl; 
    }
}

