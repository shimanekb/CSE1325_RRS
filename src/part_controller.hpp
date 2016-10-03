#ifndef PART_CONTROLLER_HPP_
#define PART_CONTROLLER_HPP_

#include "part.hpp"
#include "battery.hpp"
#include "part_view.hpp"

class PartController {
    public:
        int Execute();
    private:
        const Part* CreatePart();
        const Battery* CreateBatteryPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description);
        PartView part_view;
};

#endif
