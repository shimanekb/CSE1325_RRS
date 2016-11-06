#ifndef RRS_MODEL_ROBOT_GENERIC_VALIDATION_STRATEGY_HPP_ 
#define RRS_MODEL_ROBOT_GENERIC_VALIDATION_STRATEGY_HPP_

#include "model/robot/robot_validation_strategy.hpp"

class GenericValidationStrategy : public RobotValidationStrategy {
    public:
        GenericValidationStrategy(int max);
        int Validate(const Robot &robot, const Part &part);
    private:
        const int kMax;
};
#endif
