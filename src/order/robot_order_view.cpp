#include "order/robot_order_view.hpp"

#include <iostream>

void RobotOrderView::AskRobotModelNumber() {
    std::cout << "Enter the robot model number to order: " << std::endl;
}

void RobotOrderView::AskRobotModelQuantity() {
    std::cout << "Enter the quantity of robots to order: " << std::endl;
}

void RobotOrderView::DisplayBadRobotModelNumber() {
    std::cerr << "Robot does not exist for given robot model number." << std::endl;
}

void RobotOrderView::DisplayBadQuantityMessage() {
    std::cerr << "Invalid input for quantity, must be non-negative integer." 
        << std::endl;
}

void RobotOrderView::DisplayRobotOrder(const std::unique_ptr<RobotOrder> &robot_order) {
    std::cout << "Robot Order " << std::endl
        << "***************************" 
        << std::endl << robot_order->ToString() << std::endl;
}

void RobotOrderView::DisplayRobotOrderCreationSuccess() {
    std::cout << "Robot Order creation successful!" << std::endl;
}

void RobotOrderView::DisplayRobotOrderCreationFailure() {
    std::cout << "Robot Order creation failed!" << std::endl;
}
