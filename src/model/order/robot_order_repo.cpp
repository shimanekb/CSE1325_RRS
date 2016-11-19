#include "model/order/robot_order_repo.hpp"

#include "rrs_error.hpp"

int RobotOrderRepo::SaveRobotOrder(std::unique_ptr<RobotOrder> robot_order) {
    int error_code = RrsError::NO_ERROR;
    robot_orders.push_back(std::unique_ptr<RobotOrder>{std::move(robot_order)});

    return error_code;
}


int RobotOrderRepo::GetAllRobotOrders(std::vector<std::unique_ptr<RobotOrder>> 
        &robot_orders_vector) {
    int error_code = RrsError::NO_ERROR;
    robot_orders_vector.clear();
    
    for (const std::unique_ptr<RobotOrder> & order : robot_orders) {
        robot_orders_vector.push_back(
                std::unique_ptr<RobotOrder>{order->Clone()});
    }
    return error_code;
}
