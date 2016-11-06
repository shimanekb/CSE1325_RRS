#include "model/part/arm.hpp"

#include <sstream>

Arm::Arm(const std::string name, const int part_number, 
    const double weight, const double cost,
    const std::string description,
    const double power_consumed_watts) : kPowerConsumedWatts(power_consumed_watts), 
    Part(name, part_number, weight, cost, description, Part::PartType::ARM) {};

double Arm::GetPowerConsumedWatts() const {
    return kPowerConsumedWatts;
}

std::string Arm::ToString() const {
    std::stringstream str;
    str << "\tPart Number: " << GetPartNumber() << std::endl 
        << "\tPart Type: " << GetPartTypeString() << std::endl
        << "\tName: " << GetName() << std::endl << "\tWeight: " << GetWeight() 
        << std::endl
        << "\tCost: $" << GetCost() << std::endl << "\tPart Type: " 
        << GetPartTypeString() << std::endl << "\tDescription: " 
        << GetDescription() << std::endl << "\tPower Consumed(Watts): " 
        << GetPowerConsumedWatts() << std::endl;
    return str.str();
}

Part* Arm::Clone() const {
    return new Arm{GetName(), GetPartNumber(),
        GetWeight(), GetCost(), GetDescription(), GetPowerConsumedWatts()};
}
