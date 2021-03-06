#ifndef RRS_CONTROLLER_ORDER_ROBOT_ORDER_CONTROLLER_HPP_
#define RRS_CONTROLLER_ORDER_ROBOT_ORDER_CONTROLLER_HPP_

#include <memory>
#include <vector>

#include "model/robot/robot_repo.hpp"
#include "model/order/robot_order_repo.hpp"
#include "view/order/order_creation_window.hpp"
#include "model/part/part_repo.hpp"
#include "model/customer/customer_repo.hpp"
#include "model/sales/sales_associate_repo.hpp"

class RobotOrderController {
    public:
        int CreateRobotOrder(std::unique_ptr<RobotOrder> &orderIn, 
            const OrderCreationWindow* window);
        int GetOrders(std::vector<std::unique_ptr<RobotOrder>> &ordersIn);
    private:
        RobotOrderRepo &robot_order_repo = RobotOrderRepo::GetInstance();
        RobotRepo &robot_repo = RobotRepo::GetInstance();
        SalesAssociateRepo &salesRepo = SalesAssociateRepo::GetInstance();
        CustomerRepo &customerRepo = CustomerRepo::GetInstance();
};
#endif
