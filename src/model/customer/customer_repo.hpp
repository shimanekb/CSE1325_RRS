#ifndef RRS_MODEL_CUSTOMER_CUSTOMER_REPO_HPP_
#define RRS_MODEL_CUSTOMER_CUSTOMER_REPO_HPP_

#include <memory>
#include <vector>

#include "model/customer/customer.hpp"

class CustomerRepo {
    public:
        static CustomerRepo& GetInstance() {
            static CustomerRepo instance;
            return instance;
        }
        int SaveCustomer(std::unique_ptr<Customer> customer);
        int GetAllCustomers(std::vector<std::unique_ptr<Customer>> &customersIn);
        int GetCustomerByName(std::string name, std::unique_ptr<Customer> &customerIn);
    private:
        CustomerRepo() {};
        CustomerRepo(CustomerRepo const &);
        void operator=(CustomerRepo const&);
        std::vector<std::unique_ptr<Customer>> customers;
};

#endif
