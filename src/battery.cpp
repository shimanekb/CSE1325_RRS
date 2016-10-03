#include "battery.hpp"

Battery::Battery(std::string name, int part_number, double weight, double cost,
    std::string description, Part::PartType part_type,
    double kilowattHours) : kKilowattHours(kilowattHours), Part(name, 
        part_number, weight, cost, description, part_type) {};

double Battery::GetKilowattHours() {
    return kKilowattHours;
}
