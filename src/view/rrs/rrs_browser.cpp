#include "view/rrs/rrs_browser.hpp"

RrsBrowser::RrsBrowser(int x, int y, int w, int h) :
    Fl_Browser(x,y,w,h) {};

void RrsBrowser::ResetInput() {
    int size = this->size();
    for (int i = size; i > 1; --i)
        remove(i);
}
