#include <string>
#include <stdexcept>
#include <iostream>
#include "part_controller.hpp"
#include "rss_io.hpp"

int PartController::Execute() {
    int error = 0;
    try {
        part_repo.Add(CreatePart());
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        error = 1;
    }

    return 1;
}

std::unique_ptr<const Part> PartController::CreatePart() {
    std::unique_ptr<const Part> part;
    Part::PartType part_type;
    std::string name;
    int part_number;
    double weight;
    double cost;
    std::string description;

    part_view.AskPartType();
    if (rss_io::PartTypeIn(part_type))
        throw std::invalid_argument{"Bad part type input."};

    part_view.AskPartName();
    if(rss_io::StringIn(name))
        throw std::invalid_argument{"Bad part name input."};

    part_view.AskPartNumber();
    if(rss_io::IntIn(part_number))
        throw std::invalid_argument{"Bad part number input."};

    part_view.AskPartWeight();
    if(rss_io::DoubleIn(weight))
        throw std::invalid_argument{"Bad weight input."};

    part_view.AskPartCost();
    if(rss_io::DoubleIn(cost))
        throw std::invalid_argument{"Bad cost input."};

    part_view.AskPartDescription();
    if(rss_io::StringIn(description))
        throw std::invalid_argument{"Bad description input."};

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

    return part;
}

std::unique_ptr<const Battery> PartController::CreateBatteryPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description) { 
    double kilowattHours;
    part_view.AskForKiloWattHours();
    if (rss_io::DoubleIn(kilowattHours))
        throw std::invalid_argument{"Bad kilowatt hours input."};
    auto ptr = std::unique_ptr<const Battery>{new Battery{name, part_number, 
        weight, cost, description, kilowattHours}};
    return ptr;
}


std::unique_ptr<const Arm> PartController::CreateArmPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description) {
   double power_consumed_watts; 
   part_view.AskForPowerConsumedWatts();

   if (rss_io::DoubleIn(power_consumed_watts))
        throw std::invalid_argument{"Bad power consumed in watts input."};

   auto ptr = std::unique_ptr<const Arm>{new Arm{name, part_number, weight, 
       cost, description, power_consumed_watts}}; 
   return ptr;
}

std::unique_ptr<const Locomotor> PartController::CreateLocomotorPart(
        const std::string name, const int part_number, const double weight, 
        const double cost,const std::string description) {
   double power_consumed_watts; 
   double max_speed;

   part_view.AskForPowerConsumedWatts();
   if (rss_io::DoubleIn(power_consumed_watts))
        throw std::invalid_argument{"Bad power consumed in watts input."};

   part_view.AskForMaxMphSpeed();
   if (rss_io::DoubleIn(max_speed))
        throw std::invalid_argument{"Bad max speed input."};

   return std::unique_ptr<const Locomotor>{new Locomotor{name, part_number, weight, 
       cost, description,power_consumed_watts, max_speed}};
}


std::unique_ptr<const Torso> PartController::CreateTorsoPart(
        const std::string name, const int part_number, const double weight, 
        const double cost,const std::string description) {
   int battery_compartments; 

   part_view.AskForBatteryCompartmentSize();
   if (rss_io::IntIn(battery_compartments) || battery_compartments < 0 
           || battery_compartments > 3)
        throw std::invalid_argument{"Bad battery compartment size  input."};
   
   return std::unique_ptr<const Torso>{new Torso{name, part_number, weight, 
       cost, description, battery_compartments}};
}

std::unique_ptr<const Head> PartController::CreateHeadPart(const std::string name, 
        const int part_number, const double weight, const double cost, 
        const std::string description) {

   return std::unique_ptr<const Head>{new Head{name, part_number, weight, cost, description}};
}