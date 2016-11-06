#include "model/robot/robot_validation_strategy_repo.hpp"

#include "model/robot/battery_validation_strategy.hpp"
#include "model/robot/generic_validation_strategy.hpp"
#include "rrs_error.hpp"


int RobotValidationStrategyRepo::DetermineStrategy(Part::PartType type, 
                std::unique_ptr<RobotValidationStrategy> &strategy) {
    int error_code = RrsError::NOT_FOUND;

    switch (type) {
        case Part::PartType::BATTERY:
            strategy = std::unique_ptr<RobotValidationStrategy>{
                new BatteryValidationStrategy{}};
            error_code = RrsError::NO_ERROR;
            break;
        case Part::PartType::TORSO:
            strategy = std::unique_ptr<RobotValidationStrategy>{
                new GenericValidationStrategy{1}};
            error_code = RrsError::NO_ERROR;
            break;
        case Part::PartType::HEAD:
            strategy = std::unique_ptr<RobotValidationStrategy>{
                new GenericValidationStrategy{1}};
            error_code = RrsError::NO_ERROR;
            break;
        case Part::PartType::LOCOMOTOR:
            strategy = std::unique_ptr<RobotValidationStrategy>{
                new GenericValidationStrategy{1}};
            error_code = RrsError::NO_ERROR;
            break;
        case Part::PartType::ARM:
            strategy = std::unique_ptr<RobotValidationStrategy>{
                new GenericValidationStrategy{2}};
            error_code = RrsError::NO_ERROR;
            break;
    }

    return error_code;
}
