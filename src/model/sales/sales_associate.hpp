#ifndef RRS_MODEL_SALES_SALES_ASSOCIATE_HPP_
#define RRS_MODEL_SALES_SALES_ASSOCIATE_HPP_

#include <string>

class SalesAssociate {
    public:
        SalesAssociate(const std::string name, const int employeeNumber);
        int GetEmployeeNumber() const;
        std::string GetName() const;
        SalesAssociate* Clone();
        std::string ToString() const;
    private:
        const std::string kName;
        const int kEmployeeNumber;
};

#endif
