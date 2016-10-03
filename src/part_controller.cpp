#include<string>
#include "part_controller.hpp"
#include "rss_io.hpp"

int PartController::Execute() {
    CreatePart();
    return 0;
}

Part PartController::CreatePart() {
    Part::PartType part_type;
    std::string name;
    int part_number;
    double weight;
    double cost;
    std::string description;

    part_view.AskPartType();
    rss_io::PartTypeIn(part_type); 

    part_view.AskPartName();
    rss_io::StringIn(name);

    part_view.AskPartNumber();
    rss_io::IntIn(part_number);

    part_view.AskPartWeight();
    rss_io::DoubleIn(weight);

    part_view.AskPartCost();
    rss_io::DoubleIn(cost);

    part_view.AskPartDescription();
    rss_io::StringIn(description);

    return Part{name, part_number, weight, cost, description, part_type};
}
