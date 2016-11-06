#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

#include "rrs_manager.hpp"
#include "rrs_main_window.hpp"
#include "part/view/part_creation_window.hpp"

int main() {
    RrsMainWindow *mainWindow = new RrsMainWindow{};
    mainWindow->show();

    return Fl::run();
}
