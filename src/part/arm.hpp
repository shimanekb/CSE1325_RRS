#ifndef RRS_PART_ARM_HPP_
#define RRS_PART_ARM_HPP_

#include <string>

#include "part/part.hpp"

class Arm : public Part {
    public:
        Arm(const std::string name, const int part_number, 
                const double weight, const double cost, 
                const std::string description,
                const double power_consumed_watts);
        double GetPowerConsumedWatts() const;
        std::string ToString() const;
        std::unique_ptr<Part> GetCopy() const;
    private:
        const double kPowerConsumedWatts;
};

#endif
