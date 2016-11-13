#ifndef RRS_VIEW_ROBOT_ROBOT_BROWSER_HPP_
#define RRS_VIEW_ROBOT_ROBOT_BROWSER_HPP_

#include <memory>
#include <FL/Fl_Browser.H>

#include "model/robot/robot.hpp"

class RobotBrowser : public Fl_Browser {
    public:
        RobotBrowser(int x, int y, int w, int h);
        void ResetInput();
        int AddRobot(const std::unique_ptr<Robot> &robot);
    private:
        int widths[11] = {180, 180, 180, 0};
};

#endif 
