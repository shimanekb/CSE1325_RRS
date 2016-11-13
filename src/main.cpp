#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Browser.H>

#include "view/rrs/rrs_main_window.hpp"

int main() {
    RrsMainWindow *mainWindow = new RrsMainWindow{};
    mainWindow->show();
/**          
    Fl_Window *w = new Fl_Window{900,300};
    Fl_Browser *b = new Fl_Browser{10, 10, w->w() - 20, w->h() - 20};
    int widths[] = {50,50,0};
    b->column_widths(widths);
    b->type(FL_MULTI_BROWSER);
    b->add("NUMBER\tName");
    b->add("1234\tFOO");
    w->end();
    w->show();
    **/
    return Fl::run();
}
