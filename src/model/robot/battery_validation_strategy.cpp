#include "model/robot/battery_validation_strategy.hpp"

#include <memory>

#include "rrs_error.hpp"
#include "model/part/torso.hpp"

int BatteryValidationStrategy::Validate(const Robot &robot, const Part &part) {
    int error_code = RrsError::OUT_OF_RANGE;
    int battery_count = 1;
    int battery_max = 0;

    for(std::unique_ptr<Part> const &tmp_part : robot.GetParts()) {
        if(tmp_part->GetPartType() == Part::PartType::TORSO) {
            battery_max = static_cast<Torso*>(tmp_part->Clone())
                ->GetBatteryCompartmentSize();
        }

        if(tmp_part->GetPartType() == Part::PartType::BATTERY) {
             ++battery_count;
        }
    }
     
    if (part.GetPartType() == Part::PartType::BATTERY 
            && battery_count <= battery_max) {
       error_code = RrsError::NO_ERROR; 
    }
    return error_code;
}
