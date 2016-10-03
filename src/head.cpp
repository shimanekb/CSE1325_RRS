#include <sstream>
#include "head.hpp"

Head::Head(const std::string name, const int part_number, 
    const double weight, const double cost,
    const std::string description, const Part::PartType part_type) :
    Part(name, part_number, weight, cost, description, part_type) {};


std::string Head::ToString() const {
    std::stringstream str;
    str << GetPartNumber() << ", " << GetName() << ", " << GetWeight() << ", "
        << "$" << GetCost() << ", " << GetPartTypeString() << ", "
        << GetDescription();
    return str.str();
}


