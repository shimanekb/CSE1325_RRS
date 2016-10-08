#ifndef RRS_ROBOT_ROBOT_VIEW_HPP_
#define RRS_ROBOT_ROBOT_VIEW_HPP_

#include <memory>
#include "robot.hpp"

class RobotView {
    public:
        void AskModelName();
        void AskModelNumber();
        void AskModelPrice();
        void AskPartNumberForModel();
        void DisplayPartSelectionMenu();
        void DisplayPartSelectionSuccess();
        void DisplayPartSelectionFailure();
        void DisplayRobotParts(std::unique_ptr<Robot> const &robot);
        void DisplayRobotModel(std::unique_ptr<Robot> const &robot);
        void DisplayBadPartSelectionInput();
};
#endif
