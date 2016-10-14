#include "robot/robot_view.hpp"

#include <iostream>

void RobotView::AskModelName() {
    std::cout << "Enter a robot model name: " << std::endl;
}

void RobotView::AskModelNumber() {
    std::cout << "Enter robot model number (integers only): " <<std::endl;
}

void RobotView::AskPartNumberForModel() {
    std::cout << "Enter the part number you wish to add: " << std::endl;
}
void RobotView::AskModelPrice() {
    std::cout << "Enter the robot model price in dollars: " << std::endl;
}

void RobotView::DisplayRobotModel(std::unique_ptr<Robot> const &robot) {
    std::cout << "Robot Information" << std::endl << "**********************"
        << std::endl << robot->ToString() << std::endl;
}

void RobotView::DisplayPartSelectionMenu() {
    std::cout << std::endl
        << "Part Selection" << std::endl << "**********************" 
        << std::endl
        << "1. Add Part (by Part number)" << std::endl 
        << "2. List Current Part Selection" << std::endl
        << "3. Create Robot Model"
        << std::endl << "4. Quit to main menu" << std::endl;
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

void RobotView::DisplayRobotParts(std::vector<std::unique_ptr<Part>> const &parts) {
    std::cout << "Currently Selected Parts" << std::endl
        << "*****************************" << std::endl;
    int index = 1;
    for (std::unique_ptr<Part> const &part : parts) {
        std::cout << index++ << ". " << "\tPart Number: " << part->GetPartNumber()
           << std::endl << "\tPart Type: " << part->GetPartTypeString() << std::endl; 
    }
}

void RobotView::DisplayBadInput() {
    std::cout << "Invalid input/selection" << std::endl;
}

void RobotView::DisplayPartDoesNotExist() {
    std::cout << "Part does not exist." << std::endl;
}

void RobotView::DisplayRobotModels(std::vector<std::unique_ptr<Robot>> const &robots) {
    int enumerate = 1;
    std::cout << std::endl << "Robot Models List" << std::endl 
        << "*************************" << std::endl;
    for (std::unique_ptr<Robot> const &robot : robots) {
        std::cout << enumerate++ << ".";
        std::cout << robot->ToString();
    }

    std::cout << std::endl;
}

void RobotView::DisplayModelCreationSuccess() {
    std::cout << "Robot model successfully created." << std::endl;
}
