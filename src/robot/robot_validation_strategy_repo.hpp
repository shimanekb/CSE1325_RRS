#ifndef RRS_ROBOT_ROBOT_VALIDATION_STRATEGY_REPO_HPP_
#define RRS_ROBOT_ROBOT_VALIDATION_STRATEGY_REPO_HPP_

#include "robot_validation_strategy.hpp"

#include <memory>

#include "part.hpp"

class RobotValidationStrategyRepo {
    public:
        int DetermineStrategy(Part::PartType type, 
                std::unique_ptr<RobotValidationStrategy> &strategy);
};
#endif
