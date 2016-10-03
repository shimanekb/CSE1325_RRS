#include <sstream>
#include "torso.hpp"

Torso::Torso(const std::string name, const int part_number, 
    const double weight, const double cost,
    const std::string description, const Part::PartType part_type,
    const int battery_compartments) : kBatteryCompartments(battery_compartments), 
    Part(name, part_number, weight, cost, description, part_type) {};

int Torso::GetBatteryCompartmentSize() const {
    return kBatteryCompartments;
}

std::string Torso::ToString() const {
    std::stringstream str;
    str << GetPartNumber() << ", " << GetName() << ", " << GetWeight() << ", "
        << "$" << GetCost() << ", " << GetPartTypeString() << ", "
        << GetDescription() << ", " << GetBatteryCompartmentSize();
    return str.str();
}


