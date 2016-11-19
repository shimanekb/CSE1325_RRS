#include "model/order/robot_order.hpp"

#include <sstream>
#include <iomanip>

RobotOrder::RobotOrder(std::unique_ptr<Robot> &tmpRobot, int quantity)
    : kQuantity(quantity) {
        robot = std::unique_ptr<Robot>{std::move(tmpRobot)};
    };

std::string RobotOrder::ToString() const {
    std::stringstream ss;

    ss << "\tRobot Model Number: " << robot->GetModelNumber() << std::endl
        << "\tQuantity: " << kQuantity << std::endl
        << "\tTotal Cost: $" << std::fixed << std::setprecision(2) 
        << CalculateTotalCost() << std::endl
        << "Robot Information" << std::endl
        << "*********************************" << std::endl
        << robot->ToString();

    return ss.str();
}

double RobotOrder::CalculateTotalCost() const {
    return kQuantity * robot->GetPrice();
}

RobotOrder* RobotOrder::Clone() const {
    std::unique_ptr<Robot> tmpRobot{robot->Clone()};
    return new RobotOrder(tmpRobot, kQuantity);
}

int RobotOrder::GetQuantity() const {
    return kQuantity;
}

void RobotOrder::GetRobot(std::unique_ptr<Robot> &robotIn) const {
    robotIn = std::unique_ptr<Robot>{robot->Clone()}; 
}
