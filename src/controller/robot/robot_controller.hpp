#ifndef RRS_CONTROLLER_ROBOT_ROBOT_CONTROLLER_HPP_
#define RRS_CONTROLLER_ROBOT_ROBOT_CONTROLLER_HPP_

#include <memory>

#include "view/robot/robot_view.hpp"
#include "model/part/part_repo.hpp"
#include "model/robot/robot_repo.hpp"

class RobotController {
    public:
        int CreateRobot();
        int ShowRobots();
    private:
        int SelectParts(std::unique_ptr<Robot> const &robot);
        int GetModelNumber(int &model_number);
        int GetModelPrice(double &price);
        int GetModelName(std::string &name);
        bool VerifySelectionPartAddition(std::unique_ptr<Part> const &part, 
                std::vector<std::unique_ptr<Part>> const &part_selection);
        PartRepo &part_repo = PartRepo::GetInstance();
        RobotRepo &robot_repo = RobotRepo::GetInstance();
        RobotView robot_view;
};
#endif
