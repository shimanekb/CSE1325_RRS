#include "controller/customer/customer_controller.hpp"
#include "rrs_error.hpp"

int CustomerController::GetCustomers(std::vector<std::unique_ptr<Customer>> &customersIn) {
    customerRepo.GetAllCustomers(customersIn);
    return RrsError::NO_ERROR;
}
