#ifndef RRS_RRS_MAIN_WINDOW_HPP_
#define RRS_RRS_MAIN_WINDOW_HPP_

#include <string>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>

#include "view/rrs/rrs_window.hpp"
#include "view/part/part_creation_window.hpp"
#include "view/part/part_browser.hpp"
#include "view/robot/robot_creation_window.hpp"
#include "view/robot/robot_browser.hpp"
#include "view/order/order_creation_window.hpp"
#include "view/order/order_browser.hpp"
#include "view/customer/customer_creation_window.hpp"

class RrsMainWindow : public RrsWindow {
    public:
        RrsMainWindow();
        ~RrsMainWindow();
    private:
        RobotCreationWindow *robotCreationWindow;
        PartCreationWindow *partCreationWindow;
        OrderCreationWindow *orderCreationWindow;
        CustomerCreationWindow *customerCreationWindow;
        RobotBrowser robotBrowser;
        PartBrowser partBrowser;
        OrderBrowser orderBrowser;
        Fl_Menu_Bar menubar;
        void CreatePartOption();
        static void CreatePartOptionCallback(Fl_Widget *w, void* v);
        void CreateRobotOption();
        static void CreateRobotOptionCallback(Fl_Widget *w, void* v);
        void CreateOrderOption();
        static void CreateOrderOptionCallback(Fl_Widget *w, void* v);
        void CreateCustomerOption();
        static void CreateCustomerOptionCallback(Fl_Widget *w, void* v);
        void RefreshReports();
        static void RefreshReportsCallback(Fl_Widget *w , void* v);
        void DisplayPartBrowser();
        static void DisplayPartBrowserCallback(Fl_Widget *w , void* v);
        void DisplayRobotBrowser();
        static void DisplayRobotBrowserCallback(Fl_Widget *w , void* v);
        void DisplayOrderBrowser();
        static void DisplayOrderBrowserCallback(Fl_Widget *w , void* v);
};
#endif
