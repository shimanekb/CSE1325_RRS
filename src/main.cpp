#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

#include "view/rrs/rrs_main_window.hpp"

int main() {
    RrsMainWindow *mainWindow = new RrsMainWindow{};
    mainWindow->show();

    return Fl::run();
}
