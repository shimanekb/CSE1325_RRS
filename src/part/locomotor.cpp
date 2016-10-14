#include "part/locomotor.hpp"

#include <sstream>

Locomotor::Locomotor(const std::string name, const int part_number, 
    const double weight, const double cost,
    const std::string description,
    const double power_consumed_watts, const double max_speed) :
    kMaxSpeed(max_speed), kPowerConsumedWatts(power_consumed_watts), 
    Part(name, part_number, weight, cost, description, 
            Part::PartType::LOCOMOTOR) {};

double Locomotor::GetPowerConsumedWatts() const {
    return kPowerConsumedWatts;
}

double Locomotor::GetMaxMphSpeed() const {
    return kMaxSpeed;
}

std::string Locomotor::ToString() const {
    std::stringstream str;

    str << "\tPart Number: " << GetPartNumber() << std::endl 
       << "\tPart Type: " << GetPartTypeString() << std::endl
       << "\tPart Name: " << GetName() << std::endl << "\tPart Weight: " 
       << GetWeight() << " kg" << std::endl << "\tPart Cost: $" << GetCost() 
       << "\tPower Consumed when Operating: " << GetPowerConsumedWatts() 
       << " watts" << std::endl << "\tMax Speed: " << GetMaxMphSpeed() << " mph"
       << std::endl << "\tDescription: " << GetDescription() << std::endl;

    return str.str();
}

Part* Locomotor::Clone() const {
    return new Locomotor{GetName(), GetPartNumber(),
        GetWeight(), GetCost(), GetDescription(), GetPowerConsumedWatts(),
        GetMaxMphSpeed()};
}
