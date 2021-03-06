#include "view/rrs/rrs_main_window.hpp"

#include <memory>
#include <vector>
#include <FL/Fl_Menu_Item.H>

#include "controller/robot/robot_controller.hpp"
#include "controller/part/part_controller.hpp"
#include "controller/order/robot_order_controller.hpp"
#include "controller/customer/customer_controller.hpp"
#include "controller/sales/sales_controller.hpp"
#include "model/part/part.hpp"

RrsMainWindow::RrsMainWindow()  
    : RrsWindow(1200,585,"Robbie Robot Shop"),  
    menubar(0, 0, 1200, 25),
    robotBrowser(50, 50, 1100, 500),
    partBrowser(50, 50, 1100, 500),
    orderBrowser(50,50, 1100, 500)
{
   orderCreationWindow = new OrderCreationWindow{};
   partCreationWindow = new PartCreationWindow{};
   robotCreationWindow = new RobotCreationWindow{};
   customerCreationWindow = new CustomerCreationWindow{};
   salesCreationWindow = new SalesCreationWindow{};

   menubar.add("File/Quit", 0, WindowExitCallback, (void*) this);
   menubar.add("Create/Part", 0, CreatePartOptionCallback, (void*) this);
   menubar.add("Create/Robot", 0, CreateRobotOptionCallback, (void*) this);
   menubar.add("Create/Order", 0, CreateOrderOptionCallback, (void*) this);
   menubar.add("Create/Customer", 0, CreateCustomerOptionCallback, (void*) this);
   menubar.add("Create/Sales Associate", 0, CreateSalesAssociateOptionCallback, (void*) this);
   menubar.add("Report/Part", 0, DisplayPartBrowserCallback, (void *) this);
   menubar.add("Report/Robot", 0, DisplayRobotBrowserCallback, (void *) this);
   menubar.add("Report/Order", 0, DisplayOrderBrowserCallback, (void *) this);
   menubar.add("Report/Refresh", 0, RefreshReportsCallback, (void*) this);

   orderCreationWindow->hide();
   customerCreationWindow->hide();
   salesCreationWindow->hide();
   partBrowser.hide();
   orderBrowser.hide();
   end();
}

void RrsMainWindow::CreateOrderOptionCallback(Fl_Widget *w, void* v) {
    ((RrsMainWindow*) v)->CreateOrderOption();
}

inline void RrsMainWindow::CreateOrderOption() {
    orderCreationWindow->ResetInputs();
    RobotController controller{}; 
    CustomerController customerController{};
    SalesController salesController{};

    std::vector<std::unique_ptr<Robot>> robots;
    std::vector<std::unique_ptr<Customer>> customers;
    std::vector<std::unique_ptr<SalesAssociate>> associates;

    controller.GetRobots(robots);
    customerController.GetCustomers(customers);
    salesController.GetSalesAssociates(associates);

    orderCreationWindow->SetRobotChoice(robots);
    orderCreationWindow->SetCustomerChoice(customers);
    orderCreationWindow->SetSalesAssociateChoice(associates);

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
    RobotOrderController orderController{};

    std::vector<std::unique_ptr<Part>> parts;
    std::vector<std::unique_ptr<Robot>> robots;
    std::vector<std::unique_ptr<RobotOrder>> orders;

    robotBrowser.ResetInput();
    partBrowser.ResetInput();
    orderBrowser.ResetInput();

    controller.GetRobots(robots);
    partController.GetParts(parts);
    orderController.GetOrders(orders);

    for (std::unique_ptr<Robot> &tmpRobot: robots)
       robotBrowser.AddRobot(tmpRobot); 

    for (std::unique_ptr<Part> &tmpPart : parts)
        partBrowser.AddPart(tmpPart);

    for (std::unique_ptr<RobotOrder> &tmpOrder : orders)
        orderBrowser.AddRobotOrder(tmpOrder);
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

inline void RrsMainWindow::CreateSalesAssociateOption() {
    salesCreationWindow->ResetInputs(); 
    salesCreationWindow->show();
}

void RrsMainWindow::CreateSalesAssociateOptionCallback(Fl_Widget *w, void* v) {
    ((RrsMainWindow*) v)->CreateSalesAssociateOption();
}
inline void RrsMainWindow::CreateCustomerOption() {
    customerCreationWindow->ResetInputs();
    customerCreationWindow->show();
}

void RrsMainWindow::CreateCustomerOptionCallback(Fl_Widget *w, void* v) {
    ((RrsMainWindow*) v)->CreateCustomerOption();
}

inline void RrsMainWindow::DisplayPartBrowser() {
    robotBrowser.hide();
    orderBrowser.hide();
    partBrowser.show();
}

void RrsMainWindow::DisplayPartBrowserCallback(Fl_Widget *w , void* v) {
    ((RrsMainWindow*) v)->RefreshReports();
    ((RrsMainWindow *) v)->DisplayPartBrowser();
}

inline void RrsMainWindow::DisplayRobotBrowser() {
    partBrowser.hide();
    orderBrowser.hide();
    robotBrowser.show();
}

void RrsMainWindow::DisplayRobotBrowserCallback(Fl_Widget *w , void* v) {
    ((RrsMainWindow*) v)->RefreshReports();
    ((RrsMainWindow *) v)->DisplayRobotBrowser();
}

inline void RrsMainWindow::DisplayOrderBrowser() {
    partBrowser.hide();
    robotBrowser.hide();
    orderBrowser.show();
}

void RrsMainWindow::DisplayOrderBrowserCallback(Fl_Widget *w , void* v) {
    ((RrsMainWindow*) v)->RefreshReports();
    ((RrsMainWindow *) v)->DisplayOrderBrowser();
}

RrsMainWindow::~RrsMainWindow() {
    delete orderCreationWindow;
    delete partCreationWindow;
    delete robotCreationWindow;
    delete customerCreationWindow;
    delete salesCreationWindow;
}
