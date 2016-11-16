#ifndef RRS_VIEW_ROBOT_ROBOT_BROWSER_HPP_
#define RRS_VIEW_ROBOT_ROBOT_BROWSER_HPP_

#include <memory>

#include "view/rrs/rrs_browser.hpp"
#include "model/robot/robot.hpp"

class RobotBrowser : public RrsBrowser {
    public:
        RobotBrowser(int x, int y, int w, int h);
        int AddRobot(const std::unique_ptr<Robot> &robot);
    private:
        int widths[5] = {180,180, 180, 180,0};
};

#endif 
