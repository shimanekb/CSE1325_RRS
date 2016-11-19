#ifndef RRS_MODEL_PART_ROBOT_ORDER_HPP_
#define RRS_MODEL_PART_ROBOT_ORDER_HPP_

#include <string>
#include <memory>

#include "model/robot/robot.hpp"
#include "model/sales/sales_associate.hpp"
#include "model/customer/customer.hpp"

class RobotOrder {
    public:
        RobotOrder(std::unique_ptr<Robot> &robot, int quantity, 
                std::unique_ptr<SalesAssociate> &associate, 
                std::unique_ptr<Customer> &customer,
                const std::string date);
        std::string ToString() const;
        double CalculateTotalCost() const;
        int GetQuantity() const;
        void GetRobot(std::unique_ptr<Robot> &robotIn) const;
        void GetSalesAssociate(std::unique_ptr<SalesAssociate> &associateIn) const;
        void GetCustomer(std::unique_ptr<Customer> &customerIn) const;
        RobotOrder* Clone() const;
    private:
        const int kQuantity;
        const std::string kDate;
        std::unique_ptr<Robot> robot;
        std::unique_ptr<Customer> customer;
        std::unique_ptr<SalesAssociate> associate;
};
#endif
