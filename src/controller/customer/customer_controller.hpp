#ifndef RRS_CONTROLLER_CUSTOMER_CUSTOMER_CONTROLLER_HPP_
#define RRS_CONTROLLER_CUSTOMER_CUSTOMER_CONTROLLER_HPP_

#include <memory>
#include <vector>

#include "model/customer/customer.hpp"
#include "model/customer/customer_repo.hpp"

class CustomerController {
    public:
        int GetCustomers(std::vector<std::unique_ptr<Customer>> &customersIn);
    private:
        CustomerRepo &customerRepo = CustomerRepo::GetInstance();
};

#endif
