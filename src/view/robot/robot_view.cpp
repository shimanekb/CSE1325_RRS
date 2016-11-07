#include "view/robot/robot_view.hpp"

#include <iostream>

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
