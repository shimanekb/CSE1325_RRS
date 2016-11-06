#include "view/rrs/rrs_main_window.hpp"

#include <iostream>
#include <memory>
#include <vector>
#include <FL/Fl_Menu_Item.H>

#include "controller/robot/robot_controller.hpp"
#include "model/part/part.hpp"

RrsMainWindow::RrsMainWindow()  
    : RrsWindow(600,600,"Robbie Robot Shop"),  
    menubar(0, 0, 600, 25)
{
   partCreationWindow = new PartCreationWindow{};
   robotCreationWindow = new RobotCreationWindow{};
   menubar.add("File/Quit", 0, WindowExitCallback, (void*) this);
   menubar.add("Part/New", 0, CreatePartOptionCallback, (void*) this);
   menubar.add("Robot/New", 0, CreateRobotOptionCallback, (void*) this);
   end();
}

inline void RrsMainWindow::CreateRobotOption() {
    RobotController controller{};
    std::vector<std::unique_ptr<Part>> parts;
    controller.GetRobotComponentsByType(Part::PartType::TORSO, parts);
    robotCreationWindow->SetTorsoChoice(parts);
    robotCreationWindow->show();
}

void RrsMainWindow::CreateRobotOptionCallback(Fl_Widget *w, void* v) {
    ((RrsMainWindow*) v)->CreateRobotOption();
}

inline void RrsMainWindow::CreatePartOption() {
    partCreationWindow->show();
}

void RrsMainWindow::CreatePartOptionCallback(Fl_Widget *w, void* v) {
    ((RrsMainWindow*) v)->CreatePartOption();
}

RrsMainWindow::~RrsMainWindow() {
    delete partCreationWindow;
    delete robotCreationWindow;
}
