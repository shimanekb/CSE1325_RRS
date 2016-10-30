#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

#include "rrs_manager.hpp"
#include "part/view/part_creation_window.hpp"

int main() {
    PartCreationWindow *partCreationWindow = new PartCreationWindow{};
    partCreationWindow->show();

    return Fl::run();
}
