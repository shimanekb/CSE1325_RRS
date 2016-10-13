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

    str << "Part Number: " << GetPartNumber() << std::endl 
       << "Part Type: " << GetPartTypeString() << std::endl
       << "Part Name: " << GetName() << std::endl << "Part Weight: " 
       << GetWeight() << " kg" << std::endl << "Part Cost: $" << GetCost() 
       << std::endl << "Kilowatt Hours: " << GetKilowattHours() << std::endl
       << "Description: " << GetDescription() << std::endl;

    return str.str();
}

std::unique_ptr<Part> Battery::GetCopy() const {
    return std::unique_ptr<Part>{new Battery{GetName(), GetPartNumber(),
        GetWeight(), GetCost(), GetDescription(), GetKilowattHours()}};
}
