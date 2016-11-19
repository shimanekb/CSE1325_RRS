#include "view/customer/customer_creation_window.hpp"

#include <FL/fl_ask.H>
#include <memory>
#include <sstream>

#include "controller/customer/customer_controller.hpp"
#include "model/customer/customer.hpp"
#include "rrs_error.hpp"

CustomerCreationWindow::CustomerCreationWindow() 
    : RrsWindow(400,200,"Customer"),  
    customerName(100, 30, 150, 30, "Name: "),
    customerAddress(100, 65, 150, 30, "Address: "),
    customerPhoneNumber(100, 100, 150, 30, "Phone Number:"),
    customerEmail(100, 135, 150, 30, "Email: "),
    createButton(100, 180, 90, 30, "Create"),
    cancelButton(225, 180, 90, 30, "Cancel") {

        createButton.callback(CreateCustomerCallback, this);
        cancelButton.callback(WindowExitCallback, this);
        end();
    };

inline void CustomerCreationWindow::CreateCustomer() {
}

void CustomerCreationWindow::CreateCustomerCallback(Fl_Widget *w, void* v) {
    ((CustomerCreationWindow*) v)->CreateCustomer();
}

std::string CustomerCreationWindow::GetCustomerName() const {
    return customerName.value();
}

std::string CustomerCreationWindow::GetCustomerAddress() const {
    return customerAddress.value();
}

std::string CustomerCreationWindow::GetCustomerPhone() const {
    return customerPhoneNumber.value();
}

std::string CustomerCreationWindow::GetCustomerEmail() const {
    return customerEmail.value();
}

void CustomerCreationWindow::ResetInputs() {
    customerName.value(NULL);
    customerAddress.value(NULL);
    customerPhoneNumber.value(NULL);
    customerEmail.value(NULL);
}
