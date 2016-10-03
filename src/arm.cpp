#include <sstream>
#include "arm.hpp"

Arm::Arm(const std::string name, const int part_number, 
    const double weight, const double cost,
    const std::string description, const Part::PartType part_type,
    const double power_consumed_watts) : kPowerConsumedWatts(power_consumed_watts), 
    Part(name, part_number, weight, cost, description, part_type) {};

double Arm::GetPowerConsumedWatts() const {
    return kPowerConsumedWatts;
}

std::string Arm::ToString() const {
    std::stringstream str;
    str << GetPartNumber() << ", " << GetName() << ", " << GetWeight() << ", "
        << "$" << GetCost() << ", " << GetPartTypeString() << ", "
        << GetDescription() << ", " << GetPowerConsumedWatts();
    return str.str();
}


