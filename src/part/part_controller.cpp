#include "part/part_controller.hpp"

#include <string>
#include <iostream>

#include "rss_error.hpp"
#include "rss_io.hpp"


int PartController::ShowParts() {
    int error_code = RssError::NO_ERROR;

    part_view.DisplayParts(part_repo.GetAll());

    return error_code;
}

int PartController::CreatePart() {
    int error_code = RssError::NO_ERROR;
    std::unique_ptr<Part> part;
    Part::PartType part_type;
    std::string name;
    int part_number;
    double weight;
    double cost;
    std::string description;

    if (error_code == RssError::NO_ERROR) {
        part_view.AskPartType();
        if (rss_io::PartTypeIn(part_type))
            error_code = RssError::BAD_INPUT_TYPE;
    }

    if (error_code == RssError::NO_ERROR) {
        part_view.AskPartName();
        if(rss_io::StringIn(name))
            error_code = RssError::BAD_INPUT_TYPE;
    }

    if (error_code == RssError::NO_ERROR) {
        part_view.AskPartNumber();
        if(rss_io::IntIn(part_number))
            error_code = RssError::BAD_INPUT_TYPE;
    }

    if (error_code == RssError::NO_ERROR) {
        part_view.AskPartWeight();
        if(rss_io::DoubleIn(weight))
            error_code = RssError::BAD_INPUT_TYPE;
    }

    if (error_code == RssError::NO_ERROR) {
        part_view.AskPartCost();
        if(rss_io::DoubleIn(cost))
            error_code = RssError::BAD_INPUT_TYPE;
    }

    if (error_code == RssError::NO_ERROR) {
        part_view.AskPartDescription();
        if(rss_io::StringIn(description))
            error_code = RssError::BAD_INPUT_TYPE;
    }
    
    try {
        if (error_code == RssError::NO_ERROR) {
            if (part_type == Part::PartType::BATTERY && error_code == RssError::NO_ERROR) {
                part = CreateBatteryPart(name, part_number, weight, cost, description);
            } 
            else if (part_type == Part::PartType::ARM && error_code == RssError::NO_ERROR) {
                part = CreateArmPart(name, part_number, weight, cost, description);
            }
            else if (part_type == Part::PartType::LOCOMOTOR && error_code == RssError::NO_ERROR) {
                part = CreateLocomotorPart(name, part_number, weight, cost, description);
            }
            else if (part_type == Part::PartType::TORSO && error_code == RssError::NO_ERROR) {
                part = CreateTorsoPart(name, part_number, weight, cost, description);
            }
            else if (part_type == Part::PartType::HEAD && error_code == RssError::NO_ERROR) {
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
        error_code = RssError::BAD_INPUT_TYPE;
        std::cerr << e.what() << std::endl;
    }

    return error_code;
}

std::unique_ptr<Battery> PartController::CreateBatteryPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description) { 
    double kilowattHours;
    part_view.AskForKiloWattHours();
    if (rss_io::DoubleIn(kilowattHours))
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

   if (rss_io::DoubleIn(power_consumed_watts))
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
   if (rss_io::DoubleIn(power_consumed_watts))
        throw std::invalid_argument{"Bad power consumed in watts input."};

   part_view.AskForMaxMphSpeed();
   if (rss_io::DoubleIn(max_speed))
        throw std::invalid_argument{"Bad max speed input."};

   return std::unique_ptr<Locomotor>{new Locomotor{name, part_number, weight, 
       cost, description,power_consumed_watts, max_speed}};
}


std::unique_ptr<Torso> PartController::CreateTorsoPart(
        const std::string name, const int part_number, const double weight, 
        const double cost,const std::string description) {
   int battery_compartments; 

   part_view.AskForBatteryCompartmentSize();
   if (rss_io::IntIn(battery_compartments) || battery_compartments < 0 
           || battery_compartments > 3)
        throw std::invalid_argument{"Bad battery compartment size  input."};
   
   return std::unique_ptr<Torso>{new Torso{name, part_number, weight, 
       cost, description, battery_compartments}};
}

std::unique_ptr<Head> PartController::CreateHeadPart(const std::string name, 
        const int part_number, const double weight, const double cost, 
        const std::string description) {

   return std::unique_ptr<Head>{new Head{name, part_number, weight, cost, description}};
}
