#include "controller/order/robot_order_controller.hpp"

#include <iostream>
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
    std::string employeeNumberStr = window->GetEmployeeNumber();
    int employeeNumber;
    std::string customerName = window->GetCustomerName();
    std::string date = window->GetDate();
    std::unique_ptr<Robot> robot;
    std::unique_ptr<Customer> customer;
    std::unique_ptr<SalesAssociate> associate;

    if (modelNumberStr.compare(kEmptyChoice)) {
        error_code = rrs_io::StringToInt(modelNumberStr, modelNumber,
                0, kMax);
        error_code = robot_repo.GetRobotByModelNumber(modelNumber, robot);
    }
    else {
        error_code = RrsError::BAD_INPUT_TYPE;
    }

    if (employeeNumberStr.compare(kEmptyChoice)) {
        error_code = rrs_io::StringToInt(employeeNumberStr, employeeNumber,
                0, kMax);
        error_code = salesRepo.GetSalesAssociateByNumber(employeeNumber, associate);
    }
    else {
        error_code = RrsError::BAD_INPUT_TYPE;
    }

    if (customerName.compare(kEmptyChoice)) {
        error_code = customerRepo.GetCustomerByName(customerName, customer);
    }
    else {
        error_code = RrsError::BAD_INPUT_TYPE;
    }


    if (!error_code) {
        std::unique_ptr<Robot> tmpRobot{robot->Clone()};
        RobotOrder *tmpOrder = new RobotOrder{tmpRobot, quantity, 
            associate, customer, date};

        error_code = robot_order_repo.SaveRobotOrder(std::unique_ptr<RobotOrder>{
                tmpOrder->Clone()});
        orderIn = std::unique_ptr<RobotOrder>{tmpOrder->Clone()};

        delete tmpOrder;
    }

    return error_code;
}

int RobotOrderController::GetOrders(std::vector<std::unique_ptr<RobotOrder>> &ordersIn) {
    ordersIn.clear();
    std::vector<std::unique_ptr<RobotOrder>> orders;
    robot_order_repo.GetAllRobotOrders(orders);
    for (std::unique_ptr<RobotOrder> &tmpOrder : orders)
        ordersIn.push_back(std::unique_ptr<RobotOrder>{std::move(tmpOrder)});

    return 0;
}
