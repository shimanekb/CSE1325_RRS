#ifndef RRS_CONTROLLER_ORDER_ROBOT_ORDER_CONTROLLER_HPP_
#define RRS_CONTROLLER_ORDER_ROBOT_ORDER_CONTROLLER_HPP_

#include "model/robot/robot_repo.hpp"
#include "model/order/robot_order_repo.hpp"

class RobotOrderController {
    public:
        int CreateRobotOrder();
    private:
        RobotOrderRepo &robot_order_repo = RobotOrderRepo::GetInstance();
        RobotRepo &robot_repo = RobotRepo::GetInstance();
};
#endif
