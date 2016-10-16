#ifndef RRS_ORDER_ROBOT_ORDER_CONTROLLER_HPP_
#define RRS_ORDER_ROBOT_ORDER_CONTROLLER_HPP_

#include "order/robot_order_view.hpp"
#include "robot/robot_repo.hpp"

class RobotOrderController {
    public:
        int CreateRobotOrder();
    private:
        RobotOrderView robot_order_view;
        const RobotRepo &repo = RobotRepo::GetInstance();
};
#endif