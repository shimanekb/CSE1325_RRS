#include "part/torso.hpp"

#include <sstream>

Torso::Torso(const std::string name, const int part_number, 
    const double weight, const double cost,
    const std::string description,
    const int battery_compartments) : kBatteryCompartments(battery_compartments), 
    Part(name, part_number, weight, cost, description, Part::PartType::TORSO) {};

int Torso::GetBatteryCompartmentSize() const {
    return kBatteryCompartments;
}

std::string Torso::ToString() const {
    std::stringstream str;

    str << "\tPart Number: " << GetPartNumber() << std::endl 
       << "\tPart Type: " << GetPartTypeString() << std::endl
       << "\tPart Name: " << GetName() << std::endl << "\tPart Weight: " 
       << GetWeight() << " kg" << std::endl << "\tPart Cost: $" << GetCost() 
       << std::endl << "\tNumber of Battery Compartments: " 
       << GetBatteryCompartmentSize() << std::endl << "\tDescription: " 
       << GetDescription() << std::endl;

    return str.str();
}

Part* Torso::Clone() const {
    return new Torso{GetName(), GetPartNumber(),
        GetWeight(), GetCost(), GetDescription(), GetBatteryCompartmentSize()};
}
