#ifndef RRS_VIEW_SALES_SALES_CREATION_WINDOW_HPP_
#define RRS_VIEW_SALES_SALES_CREATION_WINDOW_HPP_

#include <string>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>

#include "view/rrs/rrs_window.hpp"

class SalesCreationWindow : public RrsWindow {
    public:
        SalesCreationWindow();
        std::string GetName() const;
        std::string GetEmployeeNumber() const;
        void ResetInputs();
    private:
        Fl_Input name;
        Fl_Int_Input employeeNumber;
        Fl_Button createButton;
        Fl_Button cancelButton;
        void CreateSalesAssociate();
        static void CreateSalesAssociateCallback(Fl_Widget *w, void* v);
};

#endif
