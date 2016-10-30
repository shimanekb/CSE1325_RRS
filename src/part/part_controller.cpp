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
                std::string name, int partNumber, Part::PartType partType, 
                double weight, double cost, std::string description, 
                int torsoBatteryCount,double armPowerConsumedWatts, 
                double locomotorMaxSpeed, double locomotorPowerConsumedWatts, 
                double batteryEnergy) {

    int error_code = RrsError::NO_ERROR;
    std::unique_ptr<Part> part;

    if (partType == Part::PartType::BATTERY) {
        part = std::unique_ptr<Battery>{new Battery{name, partNumber, 
            weight, cost, description, batteryEnergy}};
    } 
    else if (partType == Part::PartType::ARM) {
        part = std::unique_ptr<Arm>{new Arm{name, partNumber, weight, 
           cost, description, armPowerConsumedWatts}}; 
    }
    else if (partType == Part::PartType::LOCOMOTOR) {
        part = std::unique_ptr<Locomotor>{new Locomotor{name, partNumber, weight, 
           cost, description,locomotorPowerConsumedWatts, locomotorMaxSpeed}};
    }
    else if (partType == Part::PartType::TORSO) {
        part = std::unique_ptr<Torso>{new Torso{name, partNumber, weight, 
           cost, description, torsoBatteryCount}};
    }
    else if (partType == Part::PartType::HEAD) {
        part = std::unique_ptr<Head>{new Head{name, partNumber, 
            weight, cost, description}};
    }
    else {
        error_code = RrsError::BAD_INPUT_TYPE;
    }

    partIn = std::unique_ptr<Part>{part->Clone()};
    part_repo.Add(std::move(part));
    return error_code;
}
