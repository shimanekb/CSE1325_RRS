#include "model/part/head.hpp"

#include <sstream>

Head::Head(const std::string name, const int part_number, 
    const double weight, const double cost,
    const std::string description) :
    Part(name, part_number, weight, cost, description, Part::PartType::HEAD) {};


std::string Head::ToString() const {
    std::stringstream str;

    str << "\tPart Number: " << GetPartNumber() << std::endl 
       << "\tPart Type: " << GetPartTypeString() << std::endl
       << "\tPart Name: " << GetName() << std::endl << "\tPart Weight: " 
       << GetWeight() << " kg" << std::endl << "\tPart Cost: $" << GetCost() 
       << std::endl << "\tDescription: " << GetDescription() << std::endl;

    return str.str();
}

Part* Head::Clone() const {
    return new Head{GetName(), GetPartNumber(),
        GetWeight(), GetCost(), GetDescription()};
}
