#include "model/part/part.hpp"

#include <sstream>

Part::Part(const std::string name, const int part_number, const double weight,
                const double cost, std::string description, 
                const Part::PartType part_type) : kName(name), 
    kPartNumber(part_number), kWeight(weight), kCost(cost), kDescription(description), kPartType(part_type) {};

std::string Part::GetName() const {
    return kName;
}

int Part::GetPartNumber() const {
    return kPartNumber;
}

double Part::GetWeight() const {
    return kWeight;
}

double Part::GetCost() const {
    return kCost;
}

std::string Part::GetDescription() const {
    return kDescription;
}

Part::PartType Part::GetPartType() const {
    return kPartType;
}

std::string Part::GetPartTypeString() const {
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
