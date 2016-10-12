#include "battery_validation_strategy.hpp"

#include <memory>

#include "rss_error.hpp"
#include "torso.hpp"

int BatteryValidationStrategy::Validate(const Robot &robot, const Part &part) {
    int error_code = RssError::OUT_OF_RANGE;
    int battery_count = 1;
    int battery_max = 0;

    for(std::unique_ptr<Part> const &tmp_part : robot.GetParts()) {
        if(tmp_part->GetPartType() == Part::PartType::TORSO) {
            battery_max = static_cast<Torso*>((tmp_part->GetCopy()).release())
                ->GetBatteryCompartmentSize();
        }

        if(tmp_part->GetPartType() == Part::PartType::BATTERY) {
             ++battery_count;
        }
    }
     
    if (part.GetPartType() == Part::PartType::BATTERY 
            && battery_count <= battery_max) {
       error_code = RssError::NO_ERROR; 
    }
    return error_code;
}
