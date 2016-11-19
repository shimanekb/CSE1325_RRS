#include "view/order/order_creation_window.hpp"

#include <FL/fl_ask.H>
#include <sstream>

#include "controller/order/robot_order_controller.hpp"
#include "rrs_io.hpp"
#include "rrs_error.hpp"

OrderCreationWindow::OrderCreationWindow() 
    : RrsWindow(400, 280,"Robot Order"),  
    robotChoice(130, 30, 150, 30, "Robot Number:"), 
    orderQuantity(130, 65, 90, 30, "Quantity: "),
    customerChoice(130, 100, 90, 30, "Customer: "),
    associateChoice(130, 135, 90, 30, "Sales Assoc.: "),
    dateInput(130, 170, 90, 30, "Date (mm/dd/yyyy): "),
    createButton(100, 220, 90, 30, "Create"),
    cancelButton(225, 220, 90, 30, "Cancel") {
        orderQuantity.minimum(1);

        robotChoice.add("None");
        robotChoice.value(0);

        customerChoice.add("None");
        customerChoice.value(0);

        associateChoice.add("None");
        associateChoice.value(0);

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

void OrderCreationWindow::SetSalesAssociateChoice(
        const std::vector<std::unique_ptr<SalesAssociate>> &associates) {
    associateChoice.clear();
    associateChoice.add("None");
    associateChoice.value(0);

    for (const std::unique_ptr<SalesAssociate> &tmpAssoc : associates) {
        std::stringstream ss;
        ss << tmpAssoc->GetEmployeeNumber();
        associateChoice.add(ss.str().c_str());
    }
}

void OrderCreationWindow::SetCustomerChoice(
        const std::vector<std::unique_ptr<Customer>> &customers) {
    customerChoice.clear();
    customerChoice.add("None");
    customerChoice.value(0);

    for (const std::unique_ptr<Customer> &tmp : customers) {
        std::stringstream ss;
        ss << tmp->GetName();
        customerChoice.add(ss.str().c_str());
    }    
}

std::string OrderCreationWindow::GetEmployeeNumber() const {
    return associateChoice.text();
}

std::string OrderCreationWindow::GetCustomerName() const {
    return customerChoice.text();
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

std::string OrderCreationWindow::GetDate() const {
    return dateInput.value();
}

void OrderCreationWindow::ResetInputs() {
    robotChoice.clear();
    robotChoice.add("None");
    robotChoice.value(0);
    orderQuantity.value(0);

    customerChoice.clear();
    customerChoice.add("None");
    customerChoice.value(0);

    associateChoice.clear();
    associateChoice.add("None");
    associateChoice.value(0);

    dateInput.value("");
}
