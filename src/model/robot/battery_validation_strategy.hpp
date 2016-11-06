#ifndef RRS_MODEL_ROBOT_BATTERY_VALIDATION_STRATEGY_HPP_
#define RRS_MODEL_ROBOT_BATTERY_VALIDATION_STRATEGY_HPP_

#include "model/robot/robot_validation_strategy.hpp"

class BatteryValidationStrategy : public RobotValidationStrategy {
    public:
        int Validate(const Robot &robot, const Part &part);
};
#endif
