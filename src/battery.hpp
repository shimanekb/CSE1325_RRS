#ifndef BATTERY_HPP_
#define BATTERY_HPP_

#include "part.hpp"

class Battery : public Part {
    public:
        Battery(std::string name, int part_number, double weight, double cost,
                std::string description, Part::PartType part_type,
                double kilowattHours);
        double GetKilowattHours();
    private:
        const double kKilowattHours;
};

#endif
