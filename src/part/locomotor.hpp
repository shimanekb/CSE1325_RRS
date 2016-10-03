#ifndef RRS_PART_LOCOMOTOR_HPP_
#define RRS_PART_LOCOMOTOR_HPP_

#include <string>
#include "part.hpp"

class Locomotor : public Part {
    public:
        Locomotor(const std::string name, const int part_number, 
                const double weight, const double cost, 
                const std::string description,
                const double power_consumed_watts, const double max_speed);
        double GetPowerConsumedWatts() const;
        double GetMaxMphSpeed() const;
        std::string ToString() const;
    private:
        const double kPowerConsumedWatts;
        const double kMaxSpeed;
};

#endif
