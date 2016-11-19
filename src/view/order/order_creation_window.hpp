#ifndef RRS_VIEW_PART_ORDER_CREATION_WINDOW_HPP_
#define RRS_VIEW_PART_ORDER_CREATION_WINDOW_HPP_

#include <string>
#include <memory>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Spinner.H>

#include "view/rrs/rrs_window.hpp"
#include "model/robot/robot.hpp"

class OrderCreationWindow : public RrsWindow {
    public:
        OrderCreationWindow();
        std::string GetRobotNumber() const;
        int GetOrderQuantity() const;
        void SetRobotChoice(const std::vector<std::unique_ptr<Robot>> &robots);
        void ResetInputs();
    private:
        Fl_Choice robotChoice;
        Fl_Spinner orderQuantity;
        Fl_Button createButton;
        Fl_Button cancelButton;
        void CreateOrder();
        static void CreateOrderCallback(Fl_Widget *w, void* v);
};
#endif
