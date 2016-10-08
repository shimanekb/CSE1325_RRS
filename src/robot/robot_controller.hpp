#ifndef RRS_ROBOT_ROBOT_CONTROLLER_HPP_
#define RRS_ROBOT_ROBOT_CONTROLLER_HPP_

#include <memory>
#include "robot_view.hpp"
#include "part_repo.hpp"
#include "robot_repo.hpp"

class RobotController {
    public:
        int CreateRobot();
    private:
        int SelectParts(std::unique_ptr<Robot> const &robot);
        int GetModelNumber(int &model_number);
        int GetModelPrice(double &price);
        int GetModelName(std::string &name);
        PartRepo &part_repo = PartRepo::GetInstance();
        RobotRepo &robot_repo = RobotRepo::GetInstance();
        RobotView robot_view;
};
#endif
