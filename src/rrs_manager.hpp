#ifndef RRS_MANAGER_HPP_
#define RRS_MANAGER_HPP_

#include "robot_controller.hpp"
#include "part_controller.hpp"
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
        RrsManagerView rrs_view;
};

#endif
