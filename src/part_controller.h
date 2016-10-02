#ifndef PART_CONTROLLER_
#define PART_CONTROLLER_

#include "part.h"

class PartController {
    public:
        int Execute();
    private:
        Part CreatePart();
};

#endif
