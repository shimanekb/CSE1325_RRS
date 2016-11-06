#ifndef RRS_MODEL_ROBOT_ROBOT_VALIDATION_STRATEGY_REPO_HPP_
#define RRS_MODEL_ROBOT_ROBOT_VALIDATION_STRATEGY_REPO_HPP_

#include <memory>

#include "model/robot/robot_validation_strategy.hpp"
#include "model/part/part.hpp"

class RobotValidationStrategyRepo {
    public:
        int DetermineStrategy(Part::PartType type, 
                std::unique_ptr<RobotValidationStrategy> &strategy);
};
#endif
