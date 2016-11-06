#ifndef RRS_CONTROLLER_ORDER_ROBOT_ORDER_CONTROLLER_HPP_
#define RRS_CONTROLLER_ORDER_ROBOT_ORDER_CONTROLLER_HPP_

#include "view/order/robot_order_view.hpp"
#include "model/robot/robot_repo.hpp"
#include "model/order/robot_order_repo.hpp"

class RobotOrderController {
    public:
        int CreateRobotOrder();
    private:
        RobotOrderView robot_order_view;
        RobotOrderRepo &robot_order_repo = RobotOrderRepo::GetInstance();
        RobotRepo &robot_repo = RobotRepo::GetInstance();
};
#endif
