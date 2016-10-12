#ifndef RRS_ROBOT_GENERIC_VALIDATION_STRATEGY_HPP_ 
#define RRS_ROBOT_GENERIC_VALIDATION_STRATEGY_HPP_

#include "robot_validation_strategy.hpp"

class GenericValidationStrategy : public RobotValidationStrategy {
    public:
        GenericValidationStrategy(int max);
        int Validate(const Robot &robot, const Part &part);
    private:
        const int kMax;
};
#endif
