#include "model/order/robot_order.hpp"

#include <sstream>
#include <iomanip>

RobotOrder::RobotOrder(std::unique_ptr<Robot> &robotIn, int quantity, 
                std::unique_ptr<SalesAssociate> &associateIn, 
                std::unique_ptr<Customer> &customerIn,
                const std::string date) :
    kQuantity(quantity), robot(std::unique_ptr<Robot>{std::move(robotIn)}), 
    associate(std::unique_ptr<SalesAssociate>{std::move(associateIn)}),
    customer(std::unique_ptr<Customer>{std::move(customerIn)}), kDate(date) {}; 

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
    std::unique_ptr<SalesAssociate> tmpAssociate{associate->Clone()};
    std::unique_ptr<Customer> tmpCustomer{customer->Clone()};

    return new RobotOrder(tmpRobot, kQuantity, 
            tmpAssociate, tmpCustomer,
            kDate);
}

int RobotOrder::GetQuantity() const {
    return kQuantity;
}

void RobotOrder::GetRobot(std::unique_ptr<Robot> &robotIn) const {
    robotIn = std::unique_ptr<Robot>{robot->Clone()}; 
}

void RobotOrder::GetSalesAssociate(
        std::unique_ptr<SalesAssociate> &associateIn) const {
    associateIn = std::unique_ptr<SalesAssociate>{associate->Clone()};
}

void RobotOrder::GetCustomer(std::unique_ptr<Customer> &customerIn) const {
    customerIn = std::unique_ptr<Customer>{customer->Clone()};
}

