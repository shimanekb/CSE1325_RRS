#include "view/rrs/rrs_main_window.hpp"

#include <memory>
#include <vector>
#include <FL/Fl_Menu_Item.H>

#include "controller/robot/robot_controller.hpp"
#include "model/part/part.hpp"

RrsMainWindow::RrsMainWindow()  
    : RrsWindow(1200,700,"Robbie Robot Shop"),  
    menubar(0, 0, 1200, 25),
    robotBrowser(50, 50, 1100, 500)
{
   partCreationWindow = new PartCreationWindow{};
   robotCreationWindow = new RobotCreationWindow{};
   menubar.add("File/Quit", 0, WindowExitCallback, (void*) this);
   menubar.add("Create/Part", 0, CreatePartOptionCallback, (void*) this);
   menubar.add("Create/Robot", 0, CreateRobotOptionCallback, (void*) this);
   menubar.add("Report/Refresh", 0, RefreshReportsCallback, (void*) this);

   end();
}

inline void RrsMainWindow::CreateRobotOption() {
    robotCreationWindow->ResetInputs();
    RobotController controller{};
    std::vector<std::unique_ptr<Part>> parts;

    controller.GetRobotComponentsByType(Part::PartType::TORSO, parts);
    robotCreationWindow->SetTorsoChoice(parts);

    controller.GetRobotComponentsByType(Part::PartType::HEAD, parts);
    robotCreationWindow->SetHeadChoice(parts);

    controller.GetRobotComponentsByType(Part::PartType::ARM, parts);
    robotCreationWindow->SetArmChoice(parts);

    controller.GetRobotComponentsByType(Part::PartType::LOCOMOTOR, parts);
    robotCreationWindow->SetLocomotorChoice(parts);

    controller.GetRobotComponentsByType(Part::PartType::BATTERY, parts);
    robotCreationWindow->SetBatteryChoice(parts);
    robotCreationWindow->show();
}

void RrsMainWindow::CreateRobotOptionCallback(Fl_Widget *w, void* v) {
    ((RrsMainWindow*) v)->CreateRobotOption();
}


inline void RrsMainWindow::RefreshReports() {
    RobotController controller{};
    std::vector<std::unique_ptr<Robot>> robots;

    robotBrowser.ResetInput();

    controller.GetRobots(robots);
    for (std::unique_ptr<Robot> &tmpRobot: robots)
       robotBrowser.AddRobot(tmpRobot); 
}

void RrsMainWindow::RefreshReportsCallback(Fl_Widget *w , void* v) {
    ((RrsMainWindow*) v)->RefreshReports();
}

inline void RrsMainWindow::CreatePartOption() {
    partCreationWindow->ResetInputs();
    partCreationWindow->show();
}

void RrsMainWindow::CreatePartOptionCallback(Fl_Widget *w, void* v) {
    ((RrsMainWindow*) v)->CreatePartOption();
}

RrsMainWindow::~RrsMainWindow() {
    delete partCreationWindow;
    delete robotCreationWindow;
}
