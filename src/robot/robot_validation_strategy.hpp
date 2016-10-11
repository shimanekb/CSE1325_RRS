#ifndef RRS_ROBOT_ROBOT_VALIDATION_STRATEGY_HPP_
#define RRS_ROBOT_ROBOT_VALIDATION_STRATEGY_HPP_

#include <memory>
#include "part.hpp"
#include "robot.hpp"

class RobotValidationStrategy {
    public:
        virtual int Validate(std::unique_ptr<Robot> const &robot, 
            std::unique_ptr<Part> const &part) = 0;
};

#endif
