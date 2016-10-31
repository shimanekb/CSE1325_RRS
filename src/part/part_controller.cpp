#include "part/part_controller.hpp"

#include <string>
#include <iostream>

#include "rrs_error.hpp"
#include "rrs_io.hpp"

int PartController::ShowParts() {
    int error_code = RrsError::NO_ERROR;

    part_view.DisplayParts(part_repo.GetAll());

    return error_code;
}

int PartController::CreatePart(std::unique_ptr<Part> &partIn, 
        const PartCreationWindow* window) {
    int error_code = RrsError::NO_ERROR;
    constexpr int kMax = 2000000000;
    std::string name = window->GetPartName();
    int number;
    int partTypeIndex = window->GetPartTypeIndex();
    Part::PartType partType = rrs_io::PartTypeByIndex(partTypeIndex);
    double weight;
    double cost;
    std::string description = window->GetPartDescription();
    int batteryCount = window->GetTorsoBatteryCount();
    double armPowerUsed;
    double locoMaxSpeed;
    double locoPowerUsed;
    double batteryEnergyUsed;

    error_code = rrs_io::StringToInt(window->GetPartNumber(), number, 0, kMax) +
       rrs_io::StringToDouble(window->GetPartWeight(), weight, 0, kMax) +
       rrs_io::StringToDouble(window->GetPartCost(), cost, 0, kMax);

    if (!error_code) {
        if (partType == Part::PartType::ARM && !rrs_io::StringToDouble(
                    window->GetArmPowerConsumedWatts(), armPowerUsed, 0, kMax)) {
            partIn = std::unique_ptr<Arm>{new Arm{name, number, weight, 
               cost, description, armPowerUsed}}; 
        }
        else if (partType == Part::PartType::LOCOMOTOR && !rrs_io::StringToDouble(
                   window->GetLocomotorMaxSpeed(), locoMaxSpeed, 0, kMax) &&
                   !rrs_io::StringToDouble(
                   window->GetLocomotorPowerConsumedWatts(), locoPowerUsed, 0,
                   kMax)) {
            partIn = std::unique_ptr<Locomotor>{new Locomotor{name, number, weight, 
               cost, description,locoPowerUsed, locoMaxSpeed}};
        }
        else if (partType == Part::PartType::BATTERY && !rrs_io::StringToDouble(
                    window->GetBatteryEnergy(), 
                   batteryEnergyUsed, 0, kMax)) {
           partIn = std::unique_ptr<Battery>{new Battery{name, number, 
                weight, cost, description, batteryEnergyUsed}};
        }
        else if (partType == Part::PartType::HEAD) {
            partIn = std::unique_ptr<Head>{new Head{name, number, 
                weight, cost, description}};
        }
        else {
            error_code = RrsError::BAD_INPUT_TYPE;
        }
    }
    
    return error_code;
}
