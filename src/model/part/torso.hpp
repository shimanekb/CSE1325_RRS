#ifndef RRS_MODEL_PART_TORSO_HPP_
#define RRS_MODEL_PART_TORSO_HPP_

#include <string>

#include "model/part/part.hpp"

class Torso : public Part {
    public:
        Torso(const std::string name, const int part_number, 
                const double weight, const double cost, 
                const std::string description,
                const int battery_compartments);
        int GetBatteryCompartmentSize() const;
        std::string ToString() const;
        Part* Clone() const;
    private:
        const int kBatteryCompartments;
};

#endif
