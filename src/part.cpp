#include "part.h"

Part::Part(const std::string name, const int part_number, const double weight,
                const double cost, std::string description, 
                const Part::PartType part_type) : kName(name), 
    kPartNumber(part_number), kWeight(weight), kCost(cost), 
    kDescription(description), kPartType(part_type) {};

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
