#include "robot_validation_strategy_repo.hpp"

#include "battery_validation_strategy.hpp"
#include "rss_error.hpp"


int RobotValidationStrategyRepo::DetermineStrategy(Part::PartType type, 
                std::unique_ptr<RobotValidationStrategy> &strategy) {
    int error_code = RssError::NOT_FOUND;

    switch (type) {
        case Part::PartType::BATTERY:
            strategy = std::unique_ptr<RobotValidationStrategy>{
                new BatteryValidationStrategy{}};
            error_code = RssError::NO_ERROR;
            break;
    }

    return error_code;
}
