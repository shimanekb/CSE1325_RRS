#ifndef RRS_ROBOT_ROBOT_VIEW_HPP_
#define RRS_ROBOT_ROBOT_VIEW_HPP_

#include <vector>
#include <memory>
#include "robot.hpp"

class RobotView {
    public:
        void AskModelName();
        void AskModelNumber();
        void AskModelPrice();
        void DisplayBadInput();
        void AskPartNumberForModel();
        void DisplayPartSelectionMenu();
        void DisplayPartSelectionSuccess();
        void DisplayPartSelectionFailure();
        void DisplayPartDoesNotExist();
        void DisplayRobotParts(std::vector<std::unique_ptr<Part>> const &parts);
        void DisplayRobotModel(std::unique_ptr<Robot> const &robot);
        void DisplayRobotModels(std::vector<std::unique_ptr<Robot>> const &robots);
        void DisplayBadPartSelectionInput();
        void DisplayModelCreationSuccess();
};
#endif
