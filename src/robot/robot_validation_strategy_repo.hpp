#ifndef RRS_ROBOT_ROBOT_VALIDATION_STRATEGY_REPO_HPP_
#define RRS_ROBOT_ROBOT_VALIDATION_STRATEGY_REPO_HPP_

#include <memory>

#include "robot/robot_validation_strategy.hpp"
#include "part/part.hpp"

class RobotValidationStrategyRepo {
    public:
        int DetermineStrategy(Part::PartType type, 
                std::unique_ptr<RobotValidationStrategy> &strategy);
};
#endif
