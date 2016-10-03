#ifndef PART_VIEW_HPP_
#define PART_VIEW_HPP_

#include "part.hpp"

class PartView {
    public:
        void AskPartType();
        void AskPartName();
        void AskPartNumber();
        void AskPartWeight();
        void AskPartCost();
        void AskPartDescription();
        void DisplayPart(Part part);
};
#endif
