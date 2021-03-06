#ifndef RRS_MODEL_PART_LOCOMOTOR_HPP_
#define RRS_MODEL_PART_LOCOMOTOR_HPP_

#include <string>

#include "model/part/part.hpp"

class Locomotor : public Part {
    public:
        Locomotor(const std::string name, const int part_number, 
                const double weight, const double cost, 
                const std::string description,
                const double power_consumed_watts, const double max_speed);
        double GetPowerConsumedWatts() const;
        double GetMaxMphSpeed() const;
        std::string ToString() const;
        Part* Clone() const;
    private:
        const double kPowerConsumedWatts;
        const double kMaxSpeed;
};

#endif
