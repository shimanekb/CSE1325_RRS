#include <sstream>
#include "part.hpp"

Part::Part(const std::string name, const int part_number, const double weight,
                const double cost, std::string description, 
                const Part::PartType part_type) : kName(name), 
    kPartNumber(part_number), kWeight(weight), kCost(cost), kDescription(description), kPartType(part_type) {};

std::string Part::GetName() {
    return kName;
}

int Part::GetPartNumber() {
    return kPartNumber;
}

double Part::GetWeight() {
    return kWeight;
}

double Part::GetCost() {
    return kCost;
}

std::string Part::GetDescription() {
    return kDescription;
}

Part::PartType Part::GetPartType() {
    return kPartType;
}

std::string Part::ToString() {
    std::stringstream str;
    str << GetPartNumber() << ", " << GetName() << ", " << GetWeight() << ", "
        << "$" << GetCost() << ", " << GetPartTypeString() << ", "
        << GetDescription();
    return str.str();
}

std::string Part::GetPartTypeString() {
    std::string type_string;
    switch(GetPartType()) {
        case Part::PartType::TORSO:
            type_string = "Torso";
            break;
        case Part::PartType::HEAD:
            type_string = "Head";
            break;
        case Part::PartType::ARM:
            type_string = "Arm";
            break;
        case Part::PartType::LOCOMOTOR:
            type_string = "Locomotor";
            break;
        case Part::PartType::BATTERY:
            type_string = "Battery";
            break;
    }

    return type_string;
}
