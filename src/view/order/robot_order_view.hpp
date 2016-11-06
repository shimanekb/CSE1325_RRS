#ifndef RRS_VIEW_ORDER_ROBOT_ORDER_VIEW_HPP_
#define RRS_VIEW_ORDER_ROBOT_ORDER_VIEW_HPP_

#include <memory>

#include "order/robot_order.hpp"

class RobotOrderView {
    public:
        void AskRobotModelNumber();
        void AskRobotModelQuantity();
        void DisplayBadRobotModelNumber();
        void DisplayBadQuantityMessage();
        void DisplayRobotOrder(const std::unique_ptr<RobotOrder> &robot_order);
        void DisplayRobotOrderCreationSuccess();
        void DisplayRobotOrderCreationFailure();
};

#endif
