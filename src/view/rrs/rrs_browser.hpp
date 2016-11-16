#ifndef RRS_VIEW_RRS_RRS_BROWSER_HPP_
#define RRS_VIEW_RRS_RRS_BROWSER_HPP_

#include <FL/Fl_Browser.H>

class RrsBrowser : public Fl_Browser {
    public:
        RrsBrowser(int x, int y, int w, int h);
        void ResetInput();
};

#endif 
