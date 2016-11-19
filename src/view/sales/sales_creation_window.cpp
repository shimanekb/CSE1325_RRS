#include "view/sales/sales_creation_window.hpp"

#include <FL/fl_ask.H>
#include <memory>
#include <sstream>

#include "model/sales/sales_associate.hpp"
#include "rrs_error.hpp"

SalesCreationWindow::SalesCreationWindow() 
    : RrsWindow(400,180,"Sales Associate"),  
    name(150, 30, 150, 30, "Name: "),
    employeeNumber(150, 65, 150, 30, "Employee Number: "),
    createButton(100, 120, 90, 30, "Create"),
    cancelButton(225, 120, 90, 30, "Cancel") {

        createButton.callback(CreateSalesAssociateCallback, this);
        cancelButton.callback(WindowExitCallback, this);
        end();
};

inline void SalesCreationWindow::CreateSalesAssociate() {
    int errorCode = RrsError::NO_ERROR;
}

void SalesCreationWindow::CreateSalesAssociateCallback(Fl_Widget *w, void* v) {
    ((SalesCreationWindow*) v)->CreateSalesAssociate();
}

std::string SalesCreationWindow::GetName() {
    return name.value();
}

std::string SalesCreationWindow::GetEmployeeNumber() {
    return employeeNumber.value();
}

void SalesCreationWindow::ResetInputs() {
    name.value(NULL);
    employeeNumber.value(NULL);
}
