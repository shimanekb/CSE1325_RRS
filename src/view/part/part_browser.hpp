#ifndef RRS_VIEW_PART_PART_BROWSER_HPP_
#define RRS_VIEW_PART_PART_BROWSER_HPP_

#include <memory>

#include "view/rrs/rrs_browser.hpp"
#include "model/part/part.hpp"

class PartBrowser : public RrsBrowser {
    public:
        PartBrowser(int x, int y, int w, int h);
        int AddPart(const std::unique_ptr<Part> &Part);
    private:
        std::string FormatPartDetails(const std::unique_ptr<Part> &part);
        int widths[10] = {180, 180, 180,180, 180, 180,180,180, 180,0};
};

#endif 
