#include "controller/order/robot_order_controller.hpp"

#include <memory>

#include "rrs_error.hpp"
#include "rrs_io.hpp"

int RobotOrderController::CreateRobotOrder(std::unique_ptr<RobotOrder> &orderIn, 
            const OrderCreationWindow* window) {
    int error_code = RrsError::NO_ERROR;
    constexpr int kMax = 99999999999;
    const std::string kEmptyChoice = "None";
    int quantity = window->GetOrderQuantity();
    int modelNumber;
    std::string modelNumberStr = window->GetRobotNumber();
    std::unique_ptr<Robot> robot;

    if (modelNumberStr.compare(kEmptyChoice)) {
        error_code = rrs_io::StringToInt(modelNumberStr, modelNumber,
                0, kMax);
        error_code = robot_repo.GetRobotByModelNumber(modelNumber, robot);
    }
    else {
        error_code = RrsError::BAD_INPUT_TYPE;
    }

    if (!error_code) {
        std::unique_ptr<Robot> tmpRobot{robot->Clone()};
        RobotOrder *tmpOrder = new RobotOrder{tmpRobot, quantity};

        error_code = robot_order_repo.SaveRobotOrder(std::unique_ptr<RobotOrder>{
                tmpOrder->Clone()});
        orderIn = std::unique_ptr<RobotOrder>{tmpOrder->Clone()};

        delete tmpOrder;
    }

    return error_code;
}
