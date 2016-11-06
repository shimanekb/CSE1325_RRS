#include "view/robot/robot_creation_window.hpp"

#include <FL/fl_ask.H>
#include <memory>
#include <sstream>

#include "rrs_io.hpp"
#include "rrs_error.hpp"

RobotCreationWindow::RobotCreationWindow() 
    : RrsWindow(400,665,"Robot"),  
    robotTypeLabel(350,30,90,30, "Enter/choose the following options:"), 
    robotName(125,60,150,30, "Robot Name:"),
    robotNumber(125, 95, 150, 30, "Robot Number:"),
    robotCost(125, 130, 90, 30, "Robot Cost:"),
    createButton(100, 630, 90, 30, "Create"),
    cancelButton(225, 630, 90, 30, "Cancel"){

        robotTypeLabel.align(FL_ALIGN_LEFT);
        robotTypeLabel.labelfont(FL_BOLD);

        createButton.callback(CreateRobotCallback, this);
        cancelButton.callback(WindowExitCallback, this);
        end();
    };

inline void RobotCreationWindow::CreateRobot() {
    int error_code;
}

void RobotCreationWindow::CreateRobotCallback(Fl_Widget *w, void* v) {
    ((RobotCreationWindow*) v)->CreateRobot();
}
