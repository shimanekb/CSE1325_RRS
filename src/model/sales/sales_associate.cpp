#include "model/sales/sales_associate.hpp"

#include <sstream>

SalesAssociate::SalesAssociate(const std::string name, const int employeeNumber)
    : kName(name), kEmployeeNumber(employeeNumber) {};

int SalesAssociate::GetEmployeeNumber() const {
    return kEmployeeNumber;
}

std::string SalesAssociate::GetName() const {
    return kName;
}

SalesAssociate* SalesAssociate::Clone() {
    return new SalesAssociate{GetName(), GetEmployeeNumber()};
}

std::string SalesAssociate::ToString() const {
    std::stringstream ss;
    ss << "Sales Associate" << std::endl << "***********************" 
        << std::endl << "Name: " << GetName() << std::endl
        << "Employee Number: " << GetEmployeeNumber() << std::endl;

    return ss.str();
}
