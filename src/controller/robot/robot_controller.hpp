#ifndef RRS_CONTROLLER_ROBOT_ROBOT_CONTROLLER_HPP_
#define RRS_CONTROLLER_ROBOT_ROBOT_CONTROLLER_HPP_

#include <memory>
#include <vector>

#include "view/robot/robot_creation_window.hpp"
#include "view/robot/robot_view.hpp"
#include "model/part/part_repo.hpp"
#include "model/robot/robot_repo.hpp"

class RobotController {
    public:
        int CreateRobot(std::unique_ptr<Robot> &robotIn, 
            const RobotCreationWindow* window);
        int ShowRobots();
        int GetRobotComponentsByType(Part::PartType type,
                std::vector<std::unique_ptr<Part>> &parts);
    private:
        PartRepo &part_repo = PartRepo::GetInstance();
        RobotRepo &robot_repo = RobotRepo::GetInstance();
        RobotView robot_view;
};
#endif
