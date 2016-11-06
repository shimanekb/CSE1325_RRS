#include "model/order/robot_order.hpp"

#include <sstream>
#include <iomanip>

RobotOrder::RobotOrder(int robot_model_number, int quantity, double robot_cost) 
    : kRobotModelNumber(robot_model_number), kQuantity(quantity),
      kRobotCost(robot_cost) {};

std::string RobotOrder::ToString() const {
    std::stringstream ss;

    ss << "\tRobot Model Number: " << kRobotModelNumber << std::endl
        << "\tQuantity: " << kQuantity << std::endl
        << "\tTotal Cost: $" << std::fixed << std::setprecision(2) 
        << CalculateTotalCost() << std::endl;

    return ss.str();
}

double RobotOrder::CalculateTotalCost() const {
    return kQuantity * kRobotCost;
}

RobotOrder RobotOrder::Clone() const {
    return RobotOrder(kRobotModelNumber, kQuantity, kRobotCost);
}
