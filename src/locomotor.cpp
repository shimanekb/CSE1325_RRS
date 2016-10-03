#include <sstream>
#include "locomotor.hpp"

Locomotor::Locomotor(const std::string name, const int part_number, 
    const double weight, const double cost,
    const std::string description, const Part::PartType part_type,
    const double power_consumed_watts, const double max_speed) :
    kMaxSpeed(max_speed), kPowerConsumedWatts(power_consumed_watts), 
    Part(name, part_number, weight, cost, description, part_type) {};

double Locomotor::GetPowerConsumedWatts() const {
    return kPowerConsumedWatts;
}

double Locomotor::GetMaxMphSpeed() const {
    return kMaxSpeed;
}

std::string Locomotor::ToString() const {
    std::stringstream str;
    str << GetPartNumber() << ", " << GetName() << ", " << GetWeight() << ", "
        << "$" << GetCost() << ", " << GetPartTypeString() << ", "
        << GetDescription() << ", " << GetPowerConsumedWatts() << ", "
        << GetMaxMphSpeed();
    return str.str();
}


