#include "order/robot_order_controller.hpp"

#include <memory>

#include "rrs_error.hpp"
#include "rrs_io.hpp"

int RobotOrderController::CreateRobotOrder() {
    int error_code = RrsError::NO_ERROR;
    int model_number;
    int quantity;
    std::unique_ptr<Robot> robot;

    robot_order_view.AskRobotModelNumber();
    if (!rrs_io::IntIn(model_number)) {
        error_code = robot_repo.GetRobotByModelNumber(model_number, robot);
    }
    else {
        error_code = RrsError::BAD_INPUT_TYPE;
    }

        robot_order_view.DisplayBadRobotModelNumber();
    if (!error_code || rrs_io::IntIn(quantity)) {
        error_code = RrsError::BAD_INPUT_TYPE;
        robot_order_view.DisplayBadQuantityMessage();
    }

    if (!error_code) {
        error_code = robot_order_repo.SaveRobotOrder(
                std::unique_ptr<RobotOrder>{new RobotOrder(model_number, quantity, 
                        robot->GetPrice())});
    }

    if (!error_code) {
        std::vector<std::unique_ptr<RobotOrder>> tmp_orders;
        robot_order_repo.GetAllRobotOrders(tmp_orders);

        robot_order_view.DisplayRobotOrderCreationSuccess();
        robot_order_view.DisplayRobotOrder(tmp_orders.front());

        tmp_orders.clear();
    }
    else {
        robot_order_view.DisplayRobotOrderCreationFailure();
    }

    return error_code;
}
