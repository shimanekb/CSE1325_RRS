#include "battery_validation_strategy.hpp"
#include "rss_error.hpp"

int BatteryValidationStrategy::Validate(std::unique_ptr<Robot> const &robot, 
            std::unique_ptr<Part> const &part) {
    int error_code = RssError::NO_ERROR;

    return error_code;
}
