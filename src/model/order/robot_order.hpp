#ifndef RRS_MODEL_PART_ROBOT_ORDER_HPP_
#define RRS_MODEL_PART_ROBOT_ORDER_HPP_

#include <string>
#include <memory>

#include "model/robot/robot.hpp"

class RobotOrder {
    public:
        RobotOrder(std::unique_ptr<Robot> &tmpRobot, int quantity);
        std::string ToString() const;
        RobotOrder* Clone() const;
    private:
        double CalculateTotalCost() const;
        const int kQuantity;
        std::unique_ptr<Robot> robot;
};
#endif
