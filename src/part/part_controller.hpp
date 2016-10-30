#ifndef RRS_PART_PART_CONTROLLER_HPP_
#define RRS_PART_PART_CONTROLLER_HPP_

#include <memory>

#include "part/part_repo.hpp"
#include "part/part.hpp"
#include "part/battery.hpp"
#include "part/arm.hpp"
#include "part/locomotor.hpp"
#include "part/torso.hpp"
#include "part/head.hpp"
#include "part/part_view.hpp"

class PartController {
    public:
        int CreatePart(std::unique_ptr<Part> &partIn, std::string name, 
                int partNumber, Part::PartType partType, 
                double weight, double cost, std::string description, 
                int torsoBatteryCount,double armPowerConsumedWatts, 
                double locomotorMaxSpeed, double locomotorPowerConsumedWatts, 
                double batteryEnergy);
        int ShowParts();
    private:
        PartView part_view;
        PartRepo &part_repo = PartRepo::GetInstance();
};

#endif
