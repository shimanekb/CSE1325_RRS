#ifndef RRS_RRS_MAIN_WINDOW_HPP_
#define RRS_RRS_MAIN_WINDOW_HPP_

#include <string>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>

#include "view/rrs/rrs_window.hpp"
#include "view/part/part_creation_window.hpp"
#include "view/robot/robot_creation_window.hpp"
#include "view/robot/robot_browser.hpp"

class RrsMainWindow : public RrsWindow {
    public:
        RrsMainWindow();
        ~RrsMainWindow();
    private:
        RobotCreationWindow *robotCreationWindow;
        PartCreationWindow *partCreationWindow;
        RobotBrowser robotBrowser;
        Fl_Menu_Bar menubar;
        void CreatePartOption();
        static void CreatePartOptionCallback(Fl_Widget *w, void* v);
        void CreateRobotOption();
        static void CreateRobotOptionCallback(Fl_Widget *w, void* v);
        void RefreshReports();
        static void RefreshReportsCallback(Fl_Widget *w , void* v);
};
#endif
