#ifndef RRS_RRS_VIEW_RRS_WINDOW_HPP_
#define RRS_RRS_VIEW_RRS_WINDOW_HPP_

#include "FL/Fl_Window.H"

class RrsWindow : public Fl_Window {
    public:
        RrsWindow(int w, int h, const char *title=0);
    protected:
        void WindowExit();
        static void WindowExitCallback(Fl_Widget *w, void* v);
};

#endif
