#ifndef RRS_MODEL_CUSTOMER_CUSTOMER_HPP_
#define RRS_MODEL_CUSTOMER_CUSTOMER_HPP_

#include <string>

class Customer {
    public:
        Customer(const std::string name, const std::string address,
                const std::string phoneNumber, const std::string emailAddress);
        std::string GetName() const;
        std::string GetAddress() const;
        std::string GetPhoneNumber() const;
        std::string GetEmailAddress() const;
        std::string ToString() const;
        Customer *Clone() const;
    private:
        const std::string kName;
        const std::string kAddress;
        const std::string kPhoneNumber;
        const std::string kEmailAddress;
};

#endif
