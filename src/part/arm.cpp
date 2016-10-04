#include <sstream>
#include "arm.hpp"

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
    str << GetPartNumber() << ", " << GetName() << ", " << GetWeight() << ", "
        << "$" << GetCost() << ", " << GetPartTypeString() << ", "
        << GetDescription() << ", " << GetPowerConsumedWatts();
    return str.str();
}

std::unique_ptr<Part> Arm::GetCopy() const {
    return std::unique_ptr<Part>{new Arm{GetName(), GetPartNumber(),
        GetWeight(), GetCost(), GetDescription(), GetPowerConsumedWatts()}};
}
