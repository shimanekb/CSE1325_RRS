#ifndef RRS_CONTROLLER_RRS_MANAGER_HPP_
#define RRS_CONTROLLER_RRS_MANAGER_HPP_ 

#include "controller/robot/robot_controller.hpp"
#include "controller/part/part_controller.hpp"
#include "controller/order/robot_order_controller.hpp"
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
