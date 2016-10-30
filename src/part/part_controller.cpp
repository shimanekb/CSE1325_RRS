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

int PartController::CreatePart() {
    int error_code = RrsError::NO_ERROR;
    std::unique_ptr<Part> part;
    Part::PartType part_type;
    std::string name;
    int part_number;
    double weight;
    double cost;
    std::string description;

    if (error_code == RrsError::NO_ERROR) {
        part_view.AskPartType();
        error_code = rrs_io::PartTypeIn(part_type);
    }

    if (error_code == RrsError::NO_ERROR) {
        part_view.AskPartName();
        error_code = rrs_io::StringIn(name);
    }

    if (error_code == RrsError::NO_ERROR) {
        part_view.AskPartNumber();
        error_code = rrs_io::IntIn(part_number);
    }

    if (error_code == RrsError::NO_ERROR) {
        part_view.AskPartWeight();
        error_code = rrs_io::DoubleIn(weight);
    }

    if (error_code == RrsError::NO_ERROR) {
        part_view.AskPartCost();
        error_code = rrs_io::DoubleIn(cost);
    }

    if (error_code == RrsError::NO_ERROR) {
        part_view.AskPartDescription();
        error_code = rrs_io::StringIn(description);
    }
    
    try {
        if (error_code == RrsError::NO_ERROR) {
            if (part_type == Part::PartType::BATTERY) {
                part = CreateBatteryPart(name, part_number, weight, cost, description);
            } 
            else if (part_type == Part::PartType::ARM) {
                part = CreateArmPart(name, part_number, weight, cost, description);
            }
            else if (part_type == Part::PartType::LOCOMOTOR) {
                part = CreateLocomotorPart(name, part_number, weight, cost, description);
            }
            else if (part_type == Part::PartType::TORSO) {
                part = CreateTorsoPart(name, part_number, weight, cost, description);
            }
            else if (part_type == Part::PartType::HEAD) {
                part = CreateHeadPart(name, part_number, weight, cost, description);
            }

            part_view.DisplayPart(part);
            part_repo.Add(std::move(part));
        }
        else {
            std::cerr << "Bad input" << std::endl;
        }
    } 
    catch (std::invalid_argument &e) {
        error_code = RrsError::BAD_INPUT_TYPE;
        std::cerr << e.what() << std::endl;
    }

    return error_code;
}

std::unique_ptr<Battery> PartController::CreateBatteryPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description) { 
    double kilowattHours;
    part_view.AskForKiloWattHours();
    if (rrs_io::DoubleIn(kilowattHours))
        throw std::invalid_argument{"Bad kilowatt hours input."};
    auto ptr = std::unique_ptr<Battery>{new Battery{name, part_number, 
        weight, cost, description, kilowattHours}};
    return ptr;
}


std::unique_ptr<Arm> PartController::CreateArmPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description) {
   double power_consumed_watts; 
   part_view.AskForPowerConsumedWatts();

   if (rrs_io::DoubleIn(power_consumed_watts))
        throw std::invalid_argument{"Bad power consumed in watts input."};

   auto ptr = std::unique_ptr<Arm>{new Arm{name, part_number, weight, 
       cost, description, power_consumed_watts}}; 
   return ptr;
}

std::unique_ptr<Locomotor> PartController::CreateLocomotorPart(
        const std::string name, const int part_number, const double weight, 
        const double cost,const std::string description) {
   double power_consumed_watts; 
   double max_speed;

   part_view.AskForPowerConsumedWatts();
   if (rrs_io::DoubleIn(power_consumed_watts))
        throw std::invalid_argument{"Bad power consumed in watts input."};

   part_view.AskForMaxMphSpeed();
   if (rrs_io::DoubleIn(max_speed))
        throw std::invalid_argument{"Bad max speed input."};

   return std::unique_ptr<Locomotor>{new Locomotor{name, part_number, weight, 
       cost, description,power_consumed_watts, max_speed}};
}


std::unique_ptr<Torso> PartController::CreateTorsoPart(
        const std::string name, const int part_number, const double weight, 
        const double cost,const std::string description) {
   int battery_compartments; 
   constexpr int kCompartmentMin = 0;
   constexpr int kCompartmentMax = 3;

   part_view.AskForBatteryCompartmentSize();
   if (rrs_io::IntMinMaxIn(battery_compartments, 0, 3))
        throw std::invalid_argument{"Bad battery compartment size  input."};
   
   return std::unique_ptr<Torso>{new Torso{name, part_number, weight, 
       cost, description, battery_compartments}};
}

std::unique_ptr<Head> PartController::CreateHeadPart(const std::string name, 
        const int part_number, const double weight, const double cost, 
        const std::string description) {

   return std::unique_ptr<Head>{new Head{name, part_number, weight, cost, description}};
}
