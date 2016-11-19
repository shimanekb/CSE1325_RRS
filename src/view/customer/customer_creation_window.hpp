#ifndef RRS_VIEW_CUSTOMER_CUSTOMER_CREATION_WINDOW_HPP_
#define RRS_VIEW_CUSTOMER_CUSTOMER_CREATION_WINDOW_HPP_

#include <string>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>

#include "view/rrs/rrs_window.hpp"

class CustomerCreationWindow : public RrsWindow {
    public:
        CustomerCreationWindow();
        std::string GetCustomerName() const;
        std::string GetCustomerAddress() const;
        std::string GetCustomerPhone() const;
        std::string GetCustomerEmail() const;
        void ResetInputs();
    private:
        Fl_Input customerName;
        Fl_Input customerAddress;
        Fl_Input customerPhoneNumber;
        Fl_Input customerEmail;
        Fl_Button createButton;
        Fl_Button cancelButton;
        void CreateCustomer();
        static void CreateCustomerCallback(Fl_Widget *w, void* v);
};
#endif
