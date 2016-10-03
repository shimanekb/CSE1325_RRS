#include <string>
#include <stdexcept>
#include <iostream>
#include "part_controller.hpp"
#include "battery.hpp"
#include "rss_io.hpp"

int PartController::Execute() {
    int error = 0;
    try {
        const Part* part = CreatePart();
        part_view.DisplayPart(part);

        delete part;        
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        error = 1;
    }

    return 1;
}

const Part* PartController::CreatePart() {
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

    return CreateBatteryPart(name, part_number, weight, cost, description);
}

const Battery* PartController::CreateBatteryPart(const std::string name, const int part_number, 
            const double weight, const double cost, 
            const std::string description) { 
    double kilowattHours;
    part_view.AskForKiloWattHours();
    if (rss_io::DoubleIn(kilowattHours))
        throw std::invalid_argument{"Bad kilowatt hours input."};

    return new Battery{name, part_number, weight, cost, description, Part::PartType::BATTERY, 
        kilowattHours};
}
