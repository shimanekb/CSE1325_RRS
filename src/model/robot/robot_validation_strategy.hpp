#ifndef RRS_MODEL_ROBOT_ROBOT_VALIDATION_STRATEGY_HPP_
#define RRS_MODEL_ROBOT_ROBOT_VALIDATION_STRATEGY_HPP_

#include "model/part/part.hpp"
#include "model/robot/robot.hpp"

class RobotValidationStrategy {
    public:
        virtual int Validate(const Robot &robot, const Part &part) = 0;
};

#endif
