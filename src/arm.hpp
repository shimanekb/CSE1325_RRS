#ifndef ARM_HPP_
#define ARM_HPP_

#include <string>
#include "part.hpp"

class Arm : public Part {
    public:
        Arm(const std::string name, const int part_number, 
                const double weight, const double cost, 
                const std::string description, const Part::PartType part_type,
                const double power_consumed_watts);
        double GetPowerConsumedWatts() const;
        std::string ToString() const;
    private:
        const double kPowerConsumedWatts;
};

#endif
