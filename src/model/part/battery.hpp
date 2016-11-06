#ifndef RRS_MODEL_PART_BATTERY_HPP_
#define RRS_MODEL_PART_BATTERY_HPP_

#include <string>

#include "model/part/part.hpp"

class Battery : public Part {
    public:
        Battery(const std::string name, const int part_number, 
                const double weight, const double cost, 
                const std::string description,
                const double kilowatt_hours);
        double GetKilowattHours() const;
        std::string ToString() const;
        Part* Clone() const;
    private:
        const double kKilowattHours;
};

#endif
