#include "view/robot/robot_browser.hpp"

#include <sstream>
#include <FL/Fl.H>

#include "model/part/part.hpp"

RobotBrowser::RobotBrowser(int x, int y, int w, int h) 
    : RrsBrowser(x, y, w, h) {
        column_widths(widths);
        type(FL_MULTI_BROWSER);
        add("@bRobot Picture\t@bROBOT NUMBER\t@bNAME\t@bCOST\t@bPARTS (Number:Type:Price)");
        end();
}

int RobotBrowser::AddRobot(const std::unique_ptr<Robot> &robot) {
    std::vector<std::unique_ptr<Part>> tmpParts;

    std::stringstream ss{}; 
    ss << "\t" << robot->GetModelNumber() << "\t" << robot->GetName() << "\t" 
        << "$" << robot->GetPrice() << "\t";
    

    for (const std::unique_ptr<Part> &part : robot->GetParts())
        ss << part->GetPartNumber() << ":" << part->GetPartTypeString() 
            << ":$" << part->GetCost()
            <<", ";

    add(ss.str().c_str());
    icon(this->size() , (robot->GetImage())->copy(100,100));

    return 0;
}
