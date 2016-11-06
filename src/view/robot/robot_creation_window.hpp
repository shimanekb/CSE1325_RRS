#ifndef RRS_VIEW_ROBOT_ROBOT_CREATION_WINDOW_HPP_
#define RRS_VIEW_ROBOT_ROBOT_CREATION_WINDOW_HPP_

#include <string>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Button.H>

#include "view/rrs/rrs_window.hpp"

class RobotCreationWindow : public RrsWindow {
    public:
        RobotCreationWindow();
    private:
        Fl_Box robotTypeLabel;
        Fl_Input robotName;
        Fl_Int_Input robotNumber;
        Fl_Float_Input robotCost;
        Fl_Button createButton;
        Fl_Button cancelButton;
        void CreateRobot();
        static void CreateRobotCallback(Fl_Widget *w, void* v);
};
#endif
