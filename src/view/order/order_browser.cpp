#include "view/order/order_browser.hpp"

#include <sstream>
#include <FL/Fl.H>

#include "model/part/part.hpp"

OrderBrowser::OrderBrowser(int x, int y, int w, int h) 
    : RrsBrowser(x, y, w, h) {
        column_widths(widths);
        type(FL_MULTI_BROWSER);
        add("@bROBOT NUMBER\t@bROBOT COST\t@bQUANTITY\t@bTOTAL COST\t@bCUSTOMER\t@bSALES ASSOCIATE\t@bPARTS (Number:Type:Price)");
        end();
}

int OrderBrowser::AddRobotOrder(const std::unique_ptr<RobotOrder> &order) {
    std::vector<std::unique_ptr<Part>> tmpParts;
    std::unique_ptr<Robot> robot;
    std::unique_ptr<Customer> customer;
    std::unique_ptr<SalesAssociate> associate;

    order->GetRobot(robot);
    order->GetCustomer(customer);
    order->GetSalesAssociate(associate);

    std::stringstream ss{}; 
    ss << robot->GetModelNumber() << "\t"  
        << "$" << robot->GetPrice() << "\t"
        << order->GetQuantity() << "\t$" << order->CalculateTotalCost() <<"\t"
        << customer->GetName() << "\t" << associate->GetEmployeeNumber() << "\t";
    

    for (const std::unique_ptr<Part> &part : robot->GetParts())
        ss << part->GetPartNumber() << ":" << part->GetPartTypeString() 
            << ":$" << part->GetCost()
            <<", ";

    add(ss.str().c_str());

    return 0;
}
