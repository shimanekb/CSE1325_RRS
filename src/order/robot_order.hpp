#ifndef RRS_PART_ROBOT_ORDER_HPP_
#define RRS_PART_ROBOT_ORDER_HPP_

#include <string>

class RobotOrder {
    public:
        RobotOrder(int robot_model_number, int quantity, double robot_cost);
        std::string ToString() const;
        RobotOrder Clone() const;
    private:
        double CalculateTotalCost() const;
        const int kRobotModelNumber;
        const int kQuantity;
        const double kRobotCost;
};
#endif
