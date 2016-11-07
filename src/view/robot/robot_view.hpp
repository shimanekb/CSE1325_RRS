#ifndef RRS_VIEW_ROBOT_ROBOT_VIEW_HPP_
#define RRS_VIEW_ROBOT_ROBOT_VIEW_HPP_

#include <vector>
#include <memory>

#include "model/robot/robot.hpp"

class RobotView {
    public:
        void DisplayRobotModels(std::vector<std::unique_ptr<Robot>> const &robots);
};
#endif
