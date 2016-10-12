#ifndef RRS_ROBOT_BATTERY_VALIDATION_STRATEGY_HPP_
#define RRS_ROBOT_BATTERY_VALIDATION_STRATEGY_HPP_

#include "robot_validation_strategy.hpp"

class BatteryValidationStrategy : public RobotValidationStrategy {
    public:
        int Validate(const Robot &robot, const Part &part);
};
#endif
