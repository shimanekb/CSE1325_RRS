#include "part/head.hpp"

#include <sstream>

Head::Head(const std::string name, const int part_number, 
    const double weight, const double cost,
    const std::string description) :
    Part(name, part_number, weight, cost, description, Part::PartType::HEAD) {};


std::string Head::ToString() const {
    std::stringstream str;

    str << "Part Number: " << GetPartNumber() << std::endl 
       << "Part Type: " << GetPartTypeString() << std::endl
       << "Part Name: " << GetName() << std::endl << "Part Weight: " 
       << GetWeight() << " kg" << std::endl << "Part Cost: $" << GetCost() 
       << std::endl << "Description: " << GetDescription() << std::endl;

    return str.str();
}

Part* Head::Clone() const {
    return new Head{GetName(), GetPartNumber(),
        GetWeight(), GetCost(), GetDescription()};
}
