#include "view/sales/sales_creation_window.hpp"

#include <FL/fl_ask.H>
#include <memory>
#include <sstream>

#include "controller/sales/sales_controller.hpp"
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
    std::unique_ptr<SalesAssociate> associate;
    SalesController controller{};
    errorCode = controller.CreateSalesAssociate(associate, this);

    if (!errorCode) {
         std::stringstream ss;
         ss << "Sales Associate Created!" << std::endl <<std::endl << associate->ToString();
         hide();
         fl_message(ss.str().c_str());
    } 
    else {
        std::stringstream ss;
        ss << "Cannot create Sales Associate! Invalid input!" << std::endl 
            << "Cannot have:" << std::endl << "\t1. Empty inputs."
            << std::endl;
        fl_alert(ss.str().c_str());
    }
}

void SalesCreationWindow::CreateSalesAssociateCallback(Fl_Widget *w, void* v) {
    ((SalesCreationWindow*) v)->CreateSalesAssociate();
}

std::string SalesCreationWindow::GetName() const {
    return name.value();
}

std::string SalesCreationWindow::GetEmployeeNumber() const {
    return employeeNumber.value();
}

void SalesCreationWindow::ResetInputs() {
    name.value(NULL);
    employeeNumber.value(NULL);
}
