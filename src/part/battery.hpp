#ifndef BATTERY_HPP_
#define BATTERY_HPP_

#include <string>
#include "part.hpp"

class Battery : public Part {
    public:
        Battery(const std::string name, const int part_number, 
                const double weight, const double cost, 
                const std::string description,
                const double kilowattHours);
        double GetKilowattHours() const;
        std::string ToString() const;
    private:
        const double kKilowattHours;
};

#endif
