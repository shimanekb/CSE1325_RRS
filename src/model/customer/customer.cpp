#include "model/customer/customer.hpp"

#include <sstream>

Customer::Customer(const std::string name, const std::string address,
                const std::string phoneNumber, const std::string emailAddress)
    : kName(name), kAddress(address), kPhoneNumber(phoneNumber),
    kEmailAddress(emailAddress) {};

std::string Customer::GetName() const {
    return kName;
}

std::string Customer::GetAddress() const {
    return kAddress;
}

std::string Customer::GetPhoneNumber() const {
    return kPhoneNumber;
}

std::string Customer::GetEmailAddress() const {
    return kEmailAddress;
}

std::string Customer::ToString() const {
    std::stringstream ss;
    ss << "Customer" << std::endl << "*****************************" 
        << std::endl << "Name: " << GetName() << std::endl
        << "Address: " << GetAddress() << std::endl
        << "Phone Number: " << GetPhoneNumber() << std::endl
        << "Email Address: " << GetEmailAddress() << std::endl;
    
    return ss.str();
}

Customer * Customer::Clone() const {
    return new Customer{GetName(), GetAddress(), GetPhoneNumber(),
        GetEmailAddress()};
}

