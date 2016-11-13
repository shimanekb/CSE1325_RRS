#include "view/robot/robot_browser.hpp"

#include <sstream>
#include <FL/Fl.H>

#include "model/part/part.hpp"

RobotBrowser::RobotBrowser(int x, int y, int w, int h) 
    : Fl_Browser(x, y, w, h) {
        column_widths(widths);
        type(FL_MULTI_BROWSER);
        add("@bROBOT NUMBER\t@bNAME\t@bCOST\t@bParts (Number:Type)");
        end();
}


void RobotBrowser::ResetInput() {
    int size = this->size();
    for (int i = size; i > 1; --i)
        remove(i);
}

int RobotBrowser::AddRobot(const std::unique_ptr<Robot> &robot) {
    std::vector<std::unique_ptr<Part>> tmpParts;
    std::stringstream ss{}; 
    ss << robot->GetModelNumber() << "\t" << robot->GetName() << "\t" 
        << "$" << robot->GetPrice() << "\t";

    for (const std::unique_ptr<Part> &part : robot->GetParts())
        ss << part->GetPartNumber() << ":" << part->GetPartTypeString()
            <<", ";

    add(ss.str().c_str());

    return 0;
}
