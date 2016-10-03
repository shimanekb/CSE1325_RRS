#ifndef PART_CONTROLLER_HPP_
#define PART_CONTROLLER_HPP_

#include "part.hpp"
#include "part_view.hpp"

class PartController {
    public:
        int Execute();
    private:
        Part CreatePart();
        PartView part_view;
};

#endif
