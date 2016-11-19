#ifndef RRS_CONTROLLER_ROBOT_ROBOT_CONTROLLER_HPP_
#define RRS_CONTROLLER_ROBOT_ROBOT_CONTROLLER_HPP_

#include <memory>
#include <vector>

#include "view/robot/robot_creation_window.hpp"
#include "model/robot/robot_repo.hpp"
#include "model/part/part_repo.hpp"
#include "model/customer/customer_repo.hpp"
#include "model/sales/sales_associate_repo.hpp"

class RobotController {
    public:
        int CreateRobot(std::unique_ptr<Robot> &robotIn, 
            const RobotCreationWindow* window);
        int GetRobotComponentsByType(Part::PartType type,
                std::vector<std::unique_ptr<Part>> &parts);
        void GetRobots(std::vector<std::unique_ptr<Robot>> &robots);
    private:
        PartRepo &part_repo = PartRepo::GetInstance();
        RobotRepo &robot_repo = RobotRepo::GetInstance();
};
#endif
