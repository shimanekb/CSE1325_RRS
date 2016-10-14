#include "part/battery.hpp"

#include <sstream>

Battery::Battery(const std::string name, const int part_number, 
    const double weight, const double cost,
    const std::string description,
    const double kilowatt_hours) : kKilowattHours(kilowatt_hours), 
    Part(name, part_number, weight, cost, description, 
            Part::PartType::BATTERY) {};

double Battery::GetKilowattHours() const {
    return kKilowattHours;
}

std::string Battery::ToString() const {
    std::stringstream str;

    str << "\tPart Number: " << GetPartNumber() << std::endl 
       << "\tPart Type: " << GetPartTypeString() << std::endl
       << "\tPart Name: " << GetName() << std::endl << "\tPart Weight: " 
       << GetWeight() << " kg" << std::endl << "\tPart Cost: $" << GetCost() 
       << std::endl << "\tKilowatt Hours: " << GetKilowattHours() << std::endl
       << "\tDescription: " << GetDescription() << std::endl;

    return str.str();
}

Part* Battery::Clone() const {
    return new Battery{GetName(), GetPartNumber(),
        GetWeight(), GetCost(), GetDescription(), GetKilowattHours()};
}
