#include <string>
#include <stdexcept>
#include <iostream>
#include "part_controller.hpp"
#include "rss_io.hpp"

int PartController::Execute() {
    int error = 0;
    try {
        part_view.DisplayPart(CreatePart());
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        error = 1;
    }

    return 1;
}

Part PartController::CreatePart() {
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

    return Part{name, part_number, weight, cost, description, part_type};
}
