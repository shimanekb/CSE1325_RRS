#ifndef RRS_ROBOT_ROBOT_CONTROLLER_HPP_
#define RRS_ROBOT_ROBOT_CONTROLLER_HPP_

#include "part_repo.hpp"
#include "robot_repo.hpp"

class RobotController {
    public:
        int CreateRobot();
    private:
        PartRepo &part_repo = PartRepo::GetInstance();
        RobotRepo &robot_repo = RobotRepo::GetInstance();
};
#endif
