#ifndef RRS_ROBOT_ROBOT_VALIDATION_STRATEGY_HPP_
#define RRS_ROBOT_ROBOT_VALIDATION_STRATEGY_HPP_

#include "part/part.hpp"
#include "robot/robot.hpp"

class RobotValidationStrategy {
    public:
        virtual int Validate(const Robot &robot, const Part &part) = 0;
};

#endif
