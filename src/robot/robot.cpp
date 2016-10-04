#include "robot.hpp"


Robot::Robot(const std::string name, const int model_number, const double price) 
    : kName(name), kModelNumber(model_number), kPrice(price) {};

std::string Robot::GetName() const {
    return kName;
}

int Robot::GetModelNumber() const {
    return kModelNumber;
}

double Robot::GetPrice() const {
    return kPrice;
}
