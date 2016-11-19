#include "controller/customer/customer_controller.hpp"
#include "rrs_error.hpp"

int CustomerController::GetCustomers(std::vector<std::unique_ptr<Customer>> &customersIn) {
    return customerRepo.GetAllCustomers(customersIn);
}

int CustomerController::CreateCustomer(std::unique_ptr<Customer> &customerIn, 
                const CustomerCreationWindow *window) {
    int errorCode = RrsError::NO_ERROR;
    std::string name = window->GetCustomerName();
    std::string address = window->GetCustomerAddress();
    std::string phone = window->GetCustomerPhone();
    std::string email = window->GetCustomerEmail();
    Customer *customer = new Customer{name, address, phone, email}; 

    if (name.empty() || address.empty() || phone.empty() || email.empty()) {
       errorCode = RrsError::BAD_INPUT_TYPE;
    }
    else {
        customerIn = std::unique_ptr<Customer>{customer->Clone()};
        errorCode = customerRepo.SaveCustomer(std::unique_ptr<Customer>{customer});
    }

    return errorCode;
}
