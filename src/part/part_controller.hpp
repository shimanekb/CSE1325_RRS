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
        int CreatePart();
        int ShowParts();
    private:
        std::unique_ptr<Battery> CreateBatteryPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description);
        std::unique_ptr<Arm> CreateArmPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description);
        std::unique_ptr<Locomotor> CreateLocomotorPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description);
        std::unique_ptr<Torso> CreateTorsoPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description);
        std::unique_ptr<Head> CreateHeadPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description);
        PartView part_view;
        PartRepo &part_repo = PartRepo::GetInstance();
};

#endif
