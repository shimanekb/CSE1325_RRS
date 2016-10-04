#include "robot_repo.hpp"

bool RobotRepo::AddRobot(std::unique_ptr<Robot> robot) {
    robots.push_back(std::move(robot));
    return true;
}
