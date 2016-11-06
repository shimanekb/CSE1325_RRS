#include "view/rrs/rrs_window.hpp"

RrsWindow::RrsWindow(int w, int h, const char *label) 
    : Fl_Window(w, h, label) {}
inline void RrsWindow::WindowExit() {
    hide();
}

void RrsWindow::WindowExitCallback(Fl_Widget *w, void* v) {
    ((RrsWindow*) v)->WindowExit();
}
