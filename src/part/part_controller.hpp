#ifndef RRS_PART_PART_CONTROLLER_HPP_
#define RRS_PART_PART_CONTROLLER_HPP_

#include <memory>
#include "part_repo.hpp"
#include "part.hpp"
#include "battery.hpp"
#include "arm.hpp"
#include "locomotor.hpp"
#include "torso.hpp"
#include "head.hpp"
#include "part_view.hpp"

class PartController {
    public:
        int Execute();
    private:
        std::unique_ptr<const Part> CreatePart();
        std::unique_ptr<const Battery> CreateBatteryPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description);
        std::unique_ptr<const Arm> CreateArmPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description);
        std::unique_ptr<const Locomotor> CreateLocomotorPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description);
        std::unique_ptr<const Torso> CreateTorsoPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description);
        std::unique_ptr<const Head> CreateHeadPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description);
        PartView part_view;
        PartRepo &part_repo = PartRepo::GetInstance();
};

#endif
