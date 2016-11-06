#include "view/rrs/rrs_main_window.hpp"

#include <iostream>
#include <FL/Fl_Menu_Item.H>

RrsMainWindow::RrsMainWindow()  
    : RrsWindow(600,600,"Robbie Robot Shop"),  
    menubar(0, 0, 600, 25)
{
   partCreationWindow = new PartCreationWindow{};
   menubar.add("File/Quit", 0, WindowExitCallback, (void*) this);
   menubar.add("Part/New", 0, CreatePartOptionCallback, (void*) this);
   end();
}

inline void RrsMainWindow::CreatePartOption() {
    partCreationWindow->show();
}

void RrsMainWindow::CreatePartOptionCallback(Fl_Widget *w, void* v) {
    ((RrsMainWindow*) v)->CreatePartOption();
}

RrsMainWindow::~RrsMainWindow() {
    delete partCreationWindow;
}
