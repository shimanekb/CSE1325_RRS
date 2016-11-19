#include "view/rrs/rrs_main_window.hpp"

#include <memory>
#include <vector>
#include <FL/Fl_Menu_Item.H>

#include "controller/robot/robot_controller.hpp"
#include "controller/part/part_controller.hpp"
#include "model/part/part.hpp"

RrsMainWindow::RrsMainWindow()  
    : RrsWindow(1200,585,"Robbie Robot Shop"),  
    menubar(0, 0, 1200, 25),
    robotBrowser(50, 50, 1100, 500),
    partBrowser(50, 50, 1100, 500)
{
   orderCreationWindow = new OrderCreationWindow{};
   partCreationWindow = new PartCreationWindow{};
   robotCreationWindow = new RobotCreationWindow{};
   menubar.add("File/Quit", 0, WindowExitCallback, (void*) this);
   menubar.add("Create/Part", 0, CreatePartOptionCallback, (void*) this);
   menubar.add("Create/Robot", 0, CreateRobotOptionCallback, (void*) this);
   menubar.add("Create/Order", 0, CreateOrderOptionCallback, (void*) this);
   menubar.add("Report/Part", 0, DisplayPartBrowserCallback, (void *) this);
   menubar.add("Report/Robot", 0, DisplayRobotBrowserCallback, (void *) this);
   menubar.add("Report/Refresh", 0, RefreshReportsCallback, (void*) this);

   orderCreationWindow->hide();
   partBrowser.hide();
   end();
}

void RrsMainWindow::CreateOrderOptionCallback(Fl_Widget *w, void* v) {
    ((RrsMainWindow*) v)->CreateOrderOption();
}

inline void RrsMainWindow::CreateOrderOption() {
    orderCreationWindow->ResetInputs();
    orderCreationWindow->show();
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
    PartController partController{};

    std::vector<std::unique_ptr<Part>> parts;
    std::vector<std::unique_ptr<Robot>> robots;

    robotBrowser.ResetInput();
    partBrowser.ResetInput();

    controller.GetRobots(robots);
    partController.GetParts(parts);

    for (std::unique_ptr<Robot> &tmpRobot: robots)
       robotBrowser.AddRobot(tmpRobot); 

    for (std::unique_ptr<Part> &tmpPart : parts)
        partBrowser.AddPart(tmpPart);
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

inline void RrsMainWindow::DisplayPartBrowser() {
    robotBrowser.hide();
    partBrowser.show();
}

void RrsMainWindow::DisplayPartBrowserCallback(Fl_Widget *w , void* v) {
    ((RrsMainWindow *) v)->DisplayPartBrowser();
}

inline void RrsMainWindow::DisplayRobotBrowser() {
    partBrowser.hide();
    robotBrowser.show();
}

void RrsMainWindow::DisplayRobotBrowserCallback(Fl_Widget *w , void* v) {
    ((RrsMainWindow *) v)->DisplayRobotBrowser();
}

RrsMainWindow::~RrsMainWindow() {
    delete orderCreationWindow;
    delete partCreationWindow;
    delete robotCreationWindow;
}
