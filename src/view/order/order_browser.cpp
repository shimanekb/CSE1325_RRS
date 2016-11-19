#include "view/order/order_browser.hpp"

#include <sstream>
#include <FL/Fl.H>

#include "model/part/part.hpp"

OrderBrowser::OrderBrowser(int x, int y, int w, int h) 
    : RrsBrowser(x, y, w, h) {
        column_widths(widths);
        type(FL_MULTI_BROWSER);
        add("@bRobot Number\t@bROBOT COST\t@bQUANTITY\t@bTOTAL COST\t@bPARTS (Number:Type:Price)");
        end();
}

int OrderBrowser::AddRobotOrder(const std::unique_ptr<RobotOrder> &order) {
    std::vector<std::unique_ptr<Part>> tmpParts;
    std::unique_ptr<Robot> robot;

    order->GetRobot(robot);

    std::stringstream ss{}; 
    ss << robot->GetModelNumber() << "\t"  
        << "$" << robot->GetPrice() << "\t"
        << order->GetQuantity() << "\t$" << order->CalculateTotalCost() <<"\t";
    

    for (const std::unique_ptr<Part> &part : robot->GetParts())
        ss << part->GetPartNumber() << ":" << part->GetPartTypeString() 
            << ":$" << part->GetCost()
            <<", ";

    add(ss.str().c_str());

    return 0;
}
