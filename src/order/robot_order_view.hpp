#ifndef RRS_ORDER_ROBOT_ORDER_VIEW_HPP_
#define RRS_ORDER_ROBOT_ORDER_VIEW_HPP_

#include "order/robot_order.hpp"

class RobotOrderView {
    public:
        void AskRobotModelNumber();
        void AskRobotModelQuantity();
        void DisplayBadRobotModelNumber();
        void DisplayBadQuantityMessage();
        void DisplayRobotOrder(const RobotOrder &robot_order);
};
#endif
