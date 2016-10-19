#ifndef RRS_MANAGER_HPP_
#define RRS_MANAGER_HPP_

#include "robot/robot_controller.hpp"
#include "part/part_controller.hpp"
#include "order/robot_order_controller.hpp"
#include "rrs_manager_view.hpp"

class RrsManager {
    public:
        int execute();
    private:
        int MainMenu();
        int ReportMenu();
        int CreateMenu();
        PartController part_controller;
        RobotController robot_controller;
        RobotOrderController robot_order_controller;
        RrsManagerView rrs_view;
};

#endif
