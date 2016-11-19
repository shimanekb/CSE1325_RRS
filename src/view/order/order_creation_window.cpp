#include "view/order/order_creation_window.hpp"

#include <FL/fl_ask.H>
#include <sstream>

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
    int error_code;

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
