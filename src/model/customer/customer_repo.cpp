#include "model/customer/customer_repo.hpp"

#include "rrs_error.hpp"

int CustomerRepo::SaveCustomer(std::unique_ptr<Customer> customer) {
    int errorCode = RrsError::NO_ERROR;
    customers.push_back(std::unique_ptr<Customer>{customer->Clone()});

    return errorCode;
}

int CustomerRepo::GetAllCustomers(std::vector<std::unique_ptr<Customer>> &customersIn) {
    int errorCode = RrsError::NO_ERROR;
    customersIn.clear();

    for (const std::unique_ptr<Customer> &tmpCustomer : customers) {
        customersIn.push_back(std::unique_ptr<Customer>{tmpCustomer->Clone()});
    } 
    
    return errorCode;
}

int CustomerRepo::GetCustomerByName(std::string name, 
        std::unique_ptr<Customer> &customerIn) {
    int errorCode = RrsError::NOT_FOUND;
    for (const std::unique_ptr<Customer> &tmpCustomer : customers) {
        if (!name.empty() && !name.compare(tmpCustomer->GetName())) {
            errorCode = RrsError::NO_ERROR;
            customerIn = std::unique_ptr<Customer>{tmpCustomer->Clone()};
        }
    } 
    return errorCode;
}
