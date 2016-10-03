#ifndef RRS_PART_TORSO_HPP_
#define RRS_PART_TORSO_HPP_

#include <string>
#include "part.hpp"

class Torso : public Part {
    public:
        Torso(const std::string name, const int part_number, 
                const double weight, const double cost, 
                const std::string description,
                const int battery_compartments);
        int GetBatteryCompartmentSize() const;
        std::string ToString() const;
    private:
        const int kBatteryCompartments;
};

#endif
