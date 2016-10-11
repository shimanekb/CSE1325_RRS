#ifndef RRS_ROBOT_ROBOT_VALIDATION_STRATEGY_REPO_HPP_
#define RRS_ROBOT_ROBOT_VALIDATION_STRATEGY_REPO_HPP_

#include "robot_validation_strategy.hpp"

class RobotValidationStrategyRepo {
    public:
        int DetermineStrategy(Part::PartType type, 
                std::unique_ptr<RobotValidationStrategy> &strategy);
    private:
        const std::vector<RobotValidationStrategy> strategies;
};
#endif
