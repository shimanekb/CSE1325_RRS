#ifndef RRS_ROBOT_BATTERY_VALIDATION_STRATEGY_HPP_
#define RRS_ROBOT_BATTERY_VALIDATION_STRATEGY_HPP_

#include "robot_validation_strategy.hpp"

class BatteryValidationStrategy : public RobotValidationStrategy {
    public:
        int Validate(std::unique_ptr<Robot> const &robot, 
            std::unique_ptr<Part> const &part);

};
#endif
