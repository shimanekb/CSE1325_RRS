#include <sstream>
#include "torso.hpp"

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

    str << "Part Number: " << GetPartNumber() << std::endl 
       << "Part Type: " << GetPartTypeString() << std::endl
       << "Part Name: " << GetName() << std::endl << "Part Weight: " 
       << GetWeight() << " kg" << std::endl << "Part Cost: $" << GetCost() 
       << std::endl << "Number of Battery Compartments: " 
       << GetBatteryCompartmentSize() << std::endl << "Description: " 
       << GetDescription() << std::endl;

    return str.str();
}

std::unique_ptr<Part> Torso::GetCopy() const {
    return std::unique_ptr<Part>{new Torso{GetName(), GetPartNumber(),
        GetWeight(), GetCost(), GetDescription(), GetBatteryCompartmentSize()}};
}
