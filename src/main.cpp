#include <FL/Fl.H>
#include "view/rrs/rrs_main_window.hpp"


int main() {
    RrsMainWindow *mainWindow = new RrsMainWindow{};
    mainWindow->show();

    return Fl::run();
}
