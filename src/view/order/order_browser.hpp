#ifndef RRS_VIEW_ORDER_ORDER_BROWSER_HPP_
#define RRS_VIEW_ORDER_ORDER_BROWSER_HPP_

#include <memory>

#include "view/rrs/rrs_browser.hpp"
#include "model/order/robot_order.hpp"

class OrderBrowser : public RrsBrowser {
    public:
        OrderBrowser(int x, int y, int w, int h);
        int AddRobotOrder(const std::unique_ptr<RobotOrder> &order);
    private:
        int widths[5] = {180,180, 180, 180,0};
};

#endif 
