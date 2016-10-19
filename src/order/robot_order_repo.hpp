#ifndef RRS_ORDER_ROBOT_ORDER_REPO_HPP_
#define RRS_ORDER_ROBOT_ORDER_REPO_HPP_

#include <vector>
#include <memory>

#include "order/robot_order.hpp"

class RobotOrderRepo {
    public:
        static RobotOrderRepo& GetInstance() {
            static RobotOrderRepo instance;
            return instance;
        }
        int SaveRobotOrder(std::unique_ptr<RobotOrder> robot_order);
        int GetAllRobotOrders(std::vector<std::unique_ptr<RobotOrder>> &robot_orders_vector);
    private:
        RobotOrderRepo() {};
        RobotOrderRepo(RobotOrderRepo const &);
        void operator=(RobotOrderRepo const&);
        std::vector<std::unique_ptr<RobotOrder>> robot_orders;
};

#endif
