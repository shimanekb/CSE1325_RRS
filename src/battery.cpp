#include <sstream>
#include "battery.hpp"

Battery::Battery(const std::string name, const int part_number, 
    const double weight, const double cost,
    const std::string description, const Part::PartType part_type,
    const double kilowattHours) : kKilowattHours(kilowattHours), 
    Part(name, part_number, weight, cost, description, part_type) {};

double Battery::GetKilowattHours() const {
    return kKilowattHours;
}

std::string Battery::ToString() const {
    std::stringstream str;
    str << GetPartNumber() << ", " << GetName() << ", " << GetWeight() << ", "
        << "$" << GetCost() << ", " << GetPartTypeString() << ", "
        << GetDescription() << ", " << GetKilowattHours();
    return str.str();
}


