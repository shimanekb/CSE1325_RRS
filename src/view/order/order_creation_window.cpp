#include "view/order/order_creation_window.hpp"

#include <FL/fl_ask.H>
#include <sstream>

#include "controller/order/robot_order_controller.hpp"
#include "rrs_io.hpp"
#include "rrs_error.hpp"

OrderCreationWindow::OrderCreationWindow() 
    : RrsWindow(400, 150,"Robot Order"),  
    robotChoice(130, 30, 150, 30, "Robot Number:"), 
    orderQuantity(130, 65, 90, 30, "Quantity: "),
    createButton(100, 100, 90, 30, "Create"),
    cancelButton(225, 100, 90, 30, "Cancel") {
        orderQuantity.minimum(1);

        robotChoice.add("None");
        robotChoice.value(0);

        createButton.callback(CreateOrderCallback, this);
        cancelButton.callback(WindowExitCallback, this);
        end();
    };

void OrderCreationWindow::SetRobotChoice(const std::vector<std::unique_ptr<Robot>> &robots) {
    robotChoice.clear();
    robotChoice.add("None");
    robotChoice.value(0);

    for (const std::unique_ptr<Robot> &robot : robots) {
        std::stringstream ss;
        ss << robot->GetModelNumber();
        robotChoice.add(ss.str().c_str());
    }
}

std::string OrderCreationWindow::GetRobotNumber() const {
    return robotChoice.text();
}

int OrderCreationWindow::GetOrderQuantity() const {
    return orderQuantity.value();
}

inline void OrderCreationWindow::CreateOrder() {
    int error_code = RrsError::NO_ERROR;
    RobotOrderController controller{};
    std::unique_ptr<RobotOrder> order;

    error_code = controller.CreateRobotOrder(order, this);

    if (!error_code) {
         std::stringstream ss;
         ss << "Order Created!" << std::endl <<std::endl << order->ToString();
         hide();
         fl_message(ss.str().c_str());
    } 
    else {
        std::stringstream ss;
        ss << "Cannot create Order! Invalid input!" << std::endl 
            << "Cannot have:" << std::endl << "\t1. Negative numbers"
            << std::endl << "\t2. Empty Robot Model choice.";
        fl_alert(ss.str().c_str());
    }
}

void OrderCreationWindow::CreateOrderCallback(Fl_Widget *w, void* v) {
    ((OrderCreationWindow*) v)->CreateOrder();
}

void OrderCreationWindow::ResetInputs() {
    robotChoice.clear();
    robotChoice.add("None");
    robotChoice.value(0);
    orderQuantity.value(0);
}
